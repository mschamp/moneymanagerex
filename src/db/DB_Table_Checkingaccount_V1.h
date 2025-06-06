﻿// -*- C++ -*-
//=============================================================================
/**
 *      Copyright: (c) 2013 - 2025 Guan Lisheng (guanlisheng@gmail.com)
 *      Copyright: (c) 2017 - 2018 Stefano Giorgio (stef145g)
 *      Copyright: (c) 2022 Mark Whalley (mark@ipx.co.uk)
 *
 *      @file
 *
 *      @author [sqlite2cpp.py]
 *
 *      @brief
 *
 *      Revision History:
 *          AUTO GENERATED at 2025-05-08 09:16:56.228434.
 *          DO NOT EDIT!
 */
//=============================================================================
#pragma once

#include "DB_Table.h"

struct DB_Table_CHECKINGACCOUNT_V1 : public DB_Table
{
    struct Data;
    typedef DB_Table_CHECKINGACCOUNT_V1 Self;

    /** A container to hold list of Data records for the table*/
    struct Data_Set : public std::vector<Self::Data>
    {
        /**Return the data records as a json array string */
        wxString to_json() const
        {
            StringBuffer json_buffer;
            PrettyWriter<StringBuffer> json_writer(json_buffer);

            json_writer.StartArray();
            for (const auto & item: *this)
            {
                json_writer.StartObject();
                item.as_json(json_writer);
                json_writer.EndObject();
            }
            json_writer.EndArray();

            return json_buffer.GetString();
        }
    };

    /** A container to hold a list of Data record pointers for the table in memory*/
    typedef std::vector<Self::Data*> Cache;
    typedef std::map<int64, Self::Data*> Index_By_Id;
    Cache cache_;
    Index_By_Id index_by_id_;
    Data* fake_; // in case the entity not found

    /** Destructor: clears any data records stored in memory */
    ~DB_Table_CHECKINGACCOUNT_V1() 
    {
        delete this->fake_;
        destroy_cache();
    }
     
    /** Removes all records stored in memory (cache) for the table*/ 
    void destroy_cache()
    {
        std::for_each(cache_.begin(), cache_.end(), std::mem_fn(&Data::destroy));
        cache_.clear();
        index_by_id_.clear(); // no memory release since it just stores pointer and the according objects are in cache
    }

    /** Creates the database table if the table does not exist*/
    bool ensure(wxSQLite3Database* db)
    {
        if (!exists(db))
        {
            try
            {
                db->ExecuteUpdate("CREATE TABLE CHECKINGACCOUNT_V1(TRANSID integer primary key, ACCOUNTID integer NOT NULL, TOACCOUNTID integer, PAYEEID integer NOT NULL, TRANSCODE TEXT NOT NULL /* Withdrawal, Deposit, Transfer */, TRANSAMOUNT numeric NOT NULL, STATUS TEXT /* None, Reconciled, Void, Follow up, Duplicate */, TRANSACTIONNUMBER TEXT, NOTES TEXT, CATEGID integer, TRANSDATE TEXT, LASTUPDATEDTIME TEXT, DELETEDTIME TEXT, FOLLOWUPID integer, TOTRANSAMOUNT numeric, COLOR integer DEFAULT -1)");
                this->ensure_data(db);
            }
            catch(const wxSQLite3Exception &e) 
            { 
                wxLogError("CHECKINGACCOUNT_V1: Exception %s", e.GetMessage().utf8_str());
                return false;
            }
        }

        this->ensure_index(db);

        return true;
    }

    bool ensure_index(wxSQLite3Database* db)
    {
        try
        {
            db->ExecuteUpdate("CREATE INDEX IF NOT EXISTS IDX_CHECKINGACCOUNT_ACCOUNT ON CHECKINGACCOUNT_V1 (ACCOUNTID, TOACCOUNTID)");
            db->ExecuteUpdate("CREATE INDEX IF NOT EXISTS IDX_CHECKINGACCOUNT_TRANSDATE ON CHECKINGACCOUNT_V1 (TRANSDATE)");
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("CHECKINGACCOUNT_V1: Exception %s", e.GetMessage().utf8_str());
            return false;
        }

        return true;
    }

    void ensure_data(wxSQLite3Database* db)
    {
        db->Begin();
        db->Commit();
    }
    
    struct TRANSID : public DB_Column<int64>
    { 
        static wxString name() { return "TRANSID"; } 
        explicit TRANSID(const int64 &v, OP op = EQUAL): DB_Column<int64>(v, op) {}
    };
    
    struct ACCOUNTID : public DB_Column<int64>
    { 
        static wxString name() { return "ACCOUNTID"; } 
        explicit ACCOUNTID(const int64 &v, OP op = EQUAL): DB_Column<int64>(v, op) {}
    };
    
    struct TOACCOUNTID : public DB_Column<int64>
    { 
        static wxString name() { return "TOACCOUNTID"; } 
        explicit TOACCOUNTID(const int64 &v, OP op = EQUAL): DB_Column<int64>(v, op) {}
    };
    
    struct PAYEEID : public DB_Column<int64>
    { 
        static wxString name() { return "PAYEEID"; } 
        explicit PAYEEID(const int64 &v, OP op = EQUAL): DB_Column<int64>(v, op) {}
    };
    
    struct TRANSCODE : public DB_Column<wxString>
    { 
        static wxString name() { return "TRANSCODE"; } 
        explicit TRANSCODE(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct TRANSAMOUNT : public DB_Column<double>
    { 
        static wxString name() { return "TRANSAMOUNT"; } 
        explicit TRANSAMOUNT(const double &v, OP op = EQUAL): DB_Column<double>(v, op) {}
    };
    
    struct STATUS : public DB_Column<wxString>
    { 
        static wxString name() { return "STATUS"; } 
        explicit STATUS(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct TRANSACTIONNUMBER : public DB_Column<wxString>
    { 
        static wxString name() { return "TRANSACTIONNUMBER"; } 
        explicit TRANSACTIONNUMBER(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct NOTES : public DB_Column<wxString>
    { 
        static wxString name() { return "NOTES"; } 
        explicit NOTES(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct CATEGID : public DB_Column<int64>
    { 
        static wxString name() { return "CATEGID"; } 
        explicit CATEGID(const int64 &v, OP op = EQUAL): DB_Column<int64>(v, op) {}
    };
    
    struct TRANSDATE : public DB_Column<wxString>
    { 
        static wxString name() { return "TRANSDATE"; } 
        explicit TRANSDATE(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct LASTUPDATEDTIME : public DB_Column<wxString>
    { 
        static wxString name() { return "LASTUPDATEDTIME"; } 
        explicit LASTUPDATEDTIME(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct DELETEDTIME : public DB_Column<wxString>
    { 
        static wxString name() { return "DELETEDTIME"; } 
        explicit DELETEDTIME(const wxString &v, OP op = EQUAL): DB_Column<wxString>(v, op) {}
    };
    
    struct FOLLOWUPID : public DB_Column<int64>
    { 
        static wxString name() { return "FOLLOWUPID"; } 
        explicit FOLLOWUPID(const int64 &v, OP op = EQUAL): DB_Column<int64>(v, op) {}
    };
    
    struct TOTRANSAMOUNT : public DB_Column<double>
    { 
        static wxString name() { return "TOTRANSAMOUNT"; } 
        explicit TOTRANSAMOUNT(const double &v, OP op = EQUAL): DB_Column<double>(v, op) {}
    };
    
    struct COLOR : public DB_Column<int64>
    { 
        static wxString name() { return "COLOR"; } 
        explicit COLOR(const int64 &v, OP op = EQUAL): DB_Column<int64>(v, op) {}
    };
    
    typedef TRANSID PRIMARY;
    enum COLUMN
    {
        COL_TRANSID = 0
        , COL_ACCOUNTID = 1
        , COL_TOACCOUNTID = 2
        , COL_PAYEEID = 3
        , COL_TRANSCODE = 4
        , COL_TRANSAMOUNT = 5
        , COL_STATUS = 6
        , COL_TRANSACTIONNUMBER = 7
        , COL_NOTES = 8
        , COL_CATEGID = 9
        , COL_TRANSDATE = 10
        , COL_LASTUPDATEDTIME = 11
        , COL_DELETEDTIME = 12
        , COL_FOLLOWUPID = 13
        , COL_TOTRANSAMOUNT = 14
        , COL_COLOR = 15
    };

    /** Returns the column name as a string*/
    static wxString column_to_name(const COLUMN col)
    {
        switch(col)
        {
            case COL_TRANSID: return "TRANSID";
            case COL_ACCOUNTID: return "ACCOUNTID";
            case COL_TOACCOUNTID: return "TOACCOUNTID";
            case COL_PAYEEID: return "PAYEEID";
            case COL_TRANSCODE: return "TRANSCODE";
            case COL_TRANSAMOUNT: return "TRANSAMOUNT";
            case COL_STATUS: return "STATUS";
            case COL_TRANSACTIONNUMBER: return "TRANSACTIONNUMBER";
            case COL_NOTES: return "NOTES";
            case COL_CATEGID: return "CATEGID";
            case COL_TRANSDATE: return "TRANSDATE";
            case COL_LASTUPDATEDTIME: return "LASTUPDATEDTIME";
            case COL_DELETEDTIME: return "DELETEDTIME";
            case COL_FOLLOWUPID: return "FOLLOWUPID";
            case COL_TOTRANSAMOUNT: return "TOTRANSAMOUNT";
            case COL_COLOR: return "COLOR";
            default: break;
        }
        
        return "UNKNOWN";
    }

    /** Returns the column number from the given column name*/
    static COLUMN name_to_column(const wxString& name)
    {
        if ("TRANSID" == name) return COL_TRANSID;
        else if ("ACCOUNTID" == name) return COL_ACCOUNTID;
        else if ("TOACCOUNTID" == name) return COL_TOACCOUNTID;
        else if ("PAYEEID" == name) return COL_PAYEEID;
        else if ("TRANSCODE" == name) return COL_TRANSCODE;
        else if ("TRANSAMOUNT" == name) return COL_TRANSAMOUNT;
        else if ("STATUS" == name) return COL_STATUS;
        else if ("TRANSACTIONNUMBER" == name) return COL_TRANSACTIONNUMBER;
        else if ("NOTES" == name) return COL_NOTES;
        else if ("CATEGID" == name) return COL_CATEGID;
        else if ("TRANSDATE" == name) return COL_TRANSDATE;
        else if ("LASTUPDATEDTIME" == name) return COL_LASTUPDATEDTIME;
        else if ("DELETEDTIME" == name) return COL_DELETEDTIME;
        else if ("FOLLOWUPID" == name) return COL_FOLLOWUPID;
        else if ("TOTRANSAMOUNT" == name) return COL_TOTRANSAMOUNT;
        else if ("COLOR" == name) return COL_COLOR;

        return COLUMN(-1);
    }
    
    /** Data is a single record in the database table*/
    struct Data
    {
        friend struct DB_Table_CHECKINGACCOUNT_V1;
        /** This is a instance pointer to itself in memory. */
        Self* table_;
    
        int64 TRANSID;//  primary key
        int64 ACCOUNTID;
        int64 TOACCOUNTID;
        int64 PAYEEID;
        wxString TRANSCODE;
        double TRANSAMOUNT;
        wxString STATUS;
        wxString TRANSACTIONNUMBER;
        wxString NOTES;
        int64 CATEGID;
        wxString TRANSDATE;
        wxString LASTUPDATEDTIME;
        wxString DELETEDTIME;
        int64 FOLLOWUPID;
        double TOTRANSAMOUNT;
        int64 COLOR;

        int64 id() const
        {
            return TRANSID;
        }

        void id(const int64 id)
        {
            TRANSID = id;
        }

        auto operator < (const Data& other) const
        {
            return this->id() < other.id();
        }

        auto operator < (const Data* other) const
        {
            return this->id() < other->id();
        }

        bool equals(const Data* r) const
        {
            if(TRANSID != r->TRANSID) return false;
            if(ACCOUNTID != r->ACCOUNTID) return false;
            if(TOACCOUNTID != r->TOACCOUNTID) return false;
            if(PAYEEID != r->PAYEEID) return false;
            if(!TRANSCODE.IsSameAs(r->TRANSCODE)) return false;
            if(TRANSAMOUNT != r->TRANSAMOUNT) return false;
            if(!STATUS.IsSameAs(r->STATUS)) return false;
            if(!TRANSACTIONNUMBER.IsSameAs(r->TRANSACTIONNUMBER)) return false;
            if(!NOTES.IsSameAs(r->NOTES)) return false;
            if(CATEGID != r->CATEGID) return false;
            if(!TRANSDATE.IsSameAs(r->TRANSDATE)) return false;
            if(!LASTUPDATEDTIME.IsSameAs(r->LASTUPDATEDTIME)) return false;
            if(!DELETEDTIME.IsSameAs(r->DELETEDTIME)) return false;
            if(FOLLOWUPID != r->FOLLOWUPID) return false;
            if(TOTRANSAMOUNT != r->TOTRANSAMOUNT) return false;
            if(COLOR != r->COLOR) return false;
            return true;
        }
        
        explicit Data(Self* table = nullptr ) 
        {
            table_ = table;
        
            TRANSID = -1;
            ACCOUNTID = -1;
            TOACCOUNTID = -1;
            PAYEEID = -1;
            TRANSAMOUNT = 0.0;
            CATEGID = -1;
            FOLLOWUPID = -1;
            TOTRANSAMOUNT = 0.0;
            COLOR = -1;
        }

        explicit Data(wxSQLite3ResultSet& q, Self* table = nullptr )
        {
            table_ = table;
        
            TRANSID = q.GetInt64(0); // TRANSID
            ACCOUNTID = q.GetInt64(1); // ACCOUNTID
            TOACCOUNTID = q.GetInt64(2); // TOACCOUNTID
            PAYEEID = q.GetInt64(3); // PAYEEID
            TRANSCODE = q.GetString(4); // TRANSCODE
            TRANSAMOUNT = q.GetDouble(5); // TRANSAMOUNT
            STATUS = q.GetString(6); // STATUS
            TRANSACTIONNUMBER = q.GetString(7); // TRANSACTIONNUMBER
            NOTES = q.GetString(8); // NOTES
            CATEGID = q.GetInt64(9); // CATEGID
            TRANSDATE = q.GetString(10); // TRANSDATE
            LASTUPDATEDTIME = q.GetString(11); // LASTUPDATEDTIME
            DELETEDTIME = q.GetString(12); // DELETEDTIME
            FOLLOWUPID = q.GetInt64(13); // FOLLOWUPID
            TOTRANSAMOUNT = q.GetDouble(14); // TOTRANSAMOUNT
            COLOR = q.GetInt64(15); // COLOR
        }

        Data(const Data& other) = default;

        Data& operator=(const Data& other)
        {
            if (this == &other) return *this;

            TRANSID = other.TRANSID;
            ACCOUNTID = other.ACCOUNTID;
            TOACCOUNTID = other.TOACCOUNTID;
            PAYEEID = other.PAYEEID;
            TRANSCODE = other.TRANSCODE;
            TRANSAMOUNT = other.TRANSAMOUNT;
            STATUS = other.STATUS;
            TRANSACTIONNUMBER = other.TRANSACTIONNUMBER;
            NOTES = other.NOTES;
            CATEGID = other.CATEGID;
            TRANSDATE = other.TRANSDATE;
            LASTUPDATEDTIME = other.LASTUPDATEDTIME;
            DELETEDTIME = other.DELETEDTIME;
            FOLLOWUPID = other.FOLLOWUPID;
            TOTRANSAMOUNT = other.TOTRANSAMOUNT;
            COLOR = other.COLOR;
            return *this;
        }

        template<typename C>
        bool match(const C &) const
        {
            return false;
        }

        bool match(const Self::TRANSID &in) const
        {
            return this->TRANSID == in.v_;
        }

        bool match(const Self::ACCOUNTID &in) const
        {
            return this->ACCOUNTID == in.v_;
        }

        bool match(const Self::TOACCOUNTID &in) const
        {
            return this->TOACCOUNTID == in.v_;
        }

        bool match(const Self::PAYEEID &in) const
        {
            return this->PAYEEID == in.v_;
        }

        bool match(const Self::TRANSCODE &in) const
        {
            return this->TRANSCODE.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::TRANSAMOUNT &in) const
        {
            return this->TRANSAMOUNT == in.v_;
        }

        bool match(const Self::STATUS &in) const
        {
            return this->STATUS.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::TRANSACTIONNUMBER &in) const
        {
            return this->TRANSACTIONNUMBER.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::NOTES &in) const
        {
            return this->NOTES.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::CATEGID &in) const
        {
            return this->CATEGID == in.v_;
        }

        bool match(const Self::TRANSDATE &in) const
        {
            return this->TRANSDATE.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::LASTUPDATEDTIME &in) const
        {
            return this->LASTUPDATEDTIME.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::DELETEDTIME &in) const
        {
            return this->DELETEDTIME.CmpNoCase(in.v_) == 0;
        }

        bool match(const Self::FOLLOWUPID &in) const
        {
            return this->FOLLOWUPID == in.v_;
        }

        bool match(const Self::TOTRANSAMOUNT &in) const
        {
            return this->TOTRANSAMOUNT == in.v_;
        }

        bool match(const Self::COLOR &in) const
        {
            return this->COLOR == in.v_;
        }

        // Return the data record as a json string
        wxString to_json() const
        {
            StringBuffer json_buffer;
            PrettyWriter<StringBuffer> json_writer(json_buffer);

			json_writer.StartObject();			
			this->as_json(json_writer);
            json_writer.EndObject();

            return json_buffer.GetString();
        }

        // Add the field data as json key:value pairs
        void as_json(PrettyWriter<StringBuffer>& json_writer) const
        {
            json_writer.Key("TRANSID");
            json_writer.Int64(this->TRANSID.GetValue());
            json_writer.Key("ACCOUNTID");
            json_writer.Int64(this->ACCOUNTID.GetValue());
            json_writer.Key("TOACCOUNTID");
            json_writer.Int64(this->TOACCOUNTID.GetValue());
            json_writer.Key("PAYEEID");
            json_writer.Int64(this->PAYEEID.GetValue());
            json_writer.Key("TRANSCODE");
            json_writer.String(this->TRANSCODE.utf8_str());
            json_writer.Key("TRANSAMOUNT");
            json_writer.Double(this->TRANSAMOUNT);
            json_writer.Key("STATUS");
            json_writer.String(this->STATUS.utf8_str());
            json_writer.Key("TRANSACTIONNUMBER");
            json_writer.String(this->TRANSACTIONNUMBER.utf8_str());
            json_writer.Key("NOTES");
            json_writer.String(this->NOTES.utf8_str());
            json_writer.Key("CATEGID");
            json_writer.Int64(this->CATEGID.GetValue());
            json_writer.Key("TRANSDATE");
            json_writer.String(this->TRANSDATE.utf8_str());
            json_writer.Key("LASTUPDATEDTIME");
            json_writer.String(this->LASTUPDATEDTIME.utf8_str());
            json_writer.Key("DELETEDTIME");
            json_writer.String(this->DELETEDTIME.utf8_str());
            json_writer.Key("FOLLOWUPID");
            json_writer.Int64(this->FOLLOWUPID.GetValue());
            json_writer.Key("TOTRANSAMOUNT");
            json_writer.Double(this->TOTRANSAMOUNT);
            json_writer.Key("COLOR");
            json_writer.Int64(this->COLOR.GetValue());
        }

        row_t to_row_t() const
        {
            row_t row;
            row(L"TRANSID") = TRANSID.GetValue();
            row(L"ACCOUNTID") = ACCOUNTID.GetValue();
            row(L"TOACCOUNTID") = TOACCOUNTID.GetValue();
            row(L"PAYEEID") = PAYEEID.GetValue();
            row(L"TRANSCODE") = TRANSCODE;
            row(L"TRANSAMOUNT") = TRANSAMOUNT;
            row(L"STATUS") = STATUS;
            row(L"TRANSACTIONNUMBER") = TRANSACTIONNUMBER;
            row(L"NOTES") = NOTES;
            row(L"CATEGID") = CATEGID.GetValue();
            row(L"TRANSDATE") = TRANSDATE;
            row(L"LASTUPDATEDTIME") = LASTUPDATEDTIME;
            row(L"DELETEDTIME") = DELETEDTIME;
            row(L"FOLLOWUPID") = FOLLOWUPID.GetValue();
            row(L"TOTRANSAMOUNT") = TOTRANSAMOUNT;
            row(L"COLOR") = COLOR.GetValue();
            return row;
        }

        void to_template(html_template& t) const
        {
            t(L"TRANSID") = TRANSID.GetValue();
            t(L"ACCOUNTID") = ACCOUNTID.GetValue();
            t(L"TOACCOUNTID") = TOACCOUNTID.GetValue();
            t(L"PAYEEID") = PAYEEID.GetValue();
            t(L"TRANSCODE") = TRANSCODE;
            t(L"TRANSAMOUNT") = TRANSAMOUNT;
            t(L"STATUS") = STATUS;
            t(L"TRANSACTIONNUMBER") = TRANSACTIONNUMBER;
            t(L"NOTES") = NOTES;
            t(L"CATEGID") = CATEGID.GetValue();
            t(L"TRANSDATE") = TRANSDATE;
            t(L"LASTUPDATEDTIME") = LASTUPDATEDTIME;
            t(L"DELETEDTIME") = DELETEDTIME;
            t(L"FOLLOWUPID") = FOLLOWUPID.GetValue();
            t(L"TOTRANSAMOUNT") = TOTRANSAMOUNT;
            t(L"COLOR") = COLOR.GetValue();
        }

        /** Save the record instance in memory to the database. */
        bool save(wxSQLite3Database* db, bool force_insert = false)
        {
            if (db && db->IsReadOnly()) return false;
            if (!table_ || !db) 
            {
                wxLogError("can not save CHECKINGACCOUNT_V1");
                return false;
            }

            return table_->save(this, db, force_insert);
        }

        /** Remove the record instance from memory and the database. */
        bool remove(wxSQLite3Database* db)
        {
            if (!table_ || !db) 
            {
                wxLogError("can not remove CHECKINGACCOUNT_V1");
                return false;
            }
            
            return table_->remove(this, db);
        }

        void destroy()
        {
            delete this;
        }
    };

    enum
    {
        NUM_COLUMNS = 16
    };

    size_t num_columns() const { return NUM_COLUMNS; }

    /** Name of the table*/    
    wxString name() const { return "CHECKINGACCOUNT_V1"; }

    DB_Table_CHECKINGACCOUNT_V1() : fake_(new Data())
    {
        query_ = "SELECT TRANSID, ACCOUNTID, TOACCOUNTID, PAYEEID, TRANSCODE, TRANSAMOUNT, STATUS, TRANSACTIONNUMBER, NOTES, CATEGID, TRANSDATE, LASTUPDATEDTIME, DELETEDTIME, FOLLOWUPID, TOTRANSAMOUNT, COLOR FROM CHECKINGACCOUNT_V1 ";
    }

    /** Create a new Data record and add to memory table (cache)*/
    Self::Data* create()
    {
        Self::Data* entity = new Self::Data(this);
        cache_.push_back(entity);
        return entity;
    }
    
    /** Create a copy of the Data record and add to memory table (cache)*/
    Self::Data* clone(const Data* e)
    {
        Self::Data* entity = create();
        *entity = *e;
        entity->id(-1);
        return entity;
    }

    /**
    * Saves the Data record to the database table.
    * Either create a new record or update the existing record.
    * Remove old record from the memory table (cache)
    */
    bool save(Self::Data* entity, wxSQLite3Database* db, bool force_insert = false)
    {
        wxString sql = wxEmptyString;
        if (entity->id() <= 0 || force_insert) //  new & insert
        {
            sql = "INSERT INTO CHECKINGACCOUNT_V1(ACCOUNTID, TOACCOUNTID, PAYEEID, TRANSCODE, TRANSAMOUNT, STATUS, TRANSACTIONNUMBER, NOTES, CATEGID, TRANSDATE, LASTUPDATEDTIME, DELETEDTIME, FOLLOWUPID, TOTRANSAMOUNT, COLOR, TRANSID) VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        }
        else
        {
            sql = "UPDATE CHECKINGACCOUNT_V1 SET ACCOUNTID = ?, TOACCOUNTID = ?, PAYEEID = ?, TRANSCODE = ?, TRANSAMOUNT = ?, STATUS = ?, TRANSACTIONNUMBER = ?, NOTES = ?, CATEGID = ?, TRANSDATE = ?, LASTUPDATEDTIME = ?, DELETEDTIME = ?, FOLLOWUPID = ?, TOTRANSAMOUNT = ?, COLOR = ? WHERE TRANSID = ?";
        }

        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(sql);

            stmt.Bind(1, entity->ACCOUNTID);
            stmt.Bind(2, entity->TOACCOUNTID);
            stmt.Bind(3, entity->PAYEEID);
            stmt.Bind(4, entity->TRANSCODE);
            stmt.Bind(5, entity->TRANSAMOUNT);
            stmt.Bind(6, entity->STATUS);
            stmt.Bind(7, entity->TRANSACTIONNUMBER);
            stmt.Bind(8, entity->NOTES);
            stmt.Bind(9, entity->CATEGID);
            stmt.Bind(10, entity->TRANSDATE);
            stmt.Bind(11, entity->LASTUPDATEDTIME);
            stmt.Bind(12, entity->DELETEDTIME);
            stmt.Bind(13, entity->FOLLOWUPID);
            stmt.Bind(14, entity->TOTRANSAMOUNT);
            stmt.Bind(15, entity->COLOR);
            stmt.Bind(16, entity->id() > 0 ? entity->TRANSID : newId());

            stmt.ExecuteUpdate();
            stmt.Finalize();

            if (entity->id() > 0) // existent
            {
                for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
                {
                    Self::Data* e = *it;
                    if (e->id() == entity->id()) 
                        *e = *entity;  // in-place update
                }
            }
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("CHECKINGACCOUNT_V1: Exception %s, %s", e.GetMessage().utf8_str(), entity->to_json());
            return false;
        }

        if (entity->id() <= 0)
        {
            entity->id(db->GetLastRowId());
            index_by_id_.insert(std::make_pair(entity->id(), entity));
        }
        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(const int64 id, wxSQLite3Database* db)
    {
        if (id <= 0) return false;
        try
        {
            wxString sql = "DELETE FROM CHECKINGACCOUNT_V1 WHERE TRANSID = ?";
            wxSQLite3Statement stmt = db->PrepareStatement(sql);
            stmt.Bind(1, id);
            stmt.ExecuteUpdate();
            stmt.Finalize();

            Cache c;
            for(Cache::iterator it = cache_.begin(); it != cache_.end(); ++ it)
            {
                Self::Data* entity = *it;
                if (entity->id() == id) 
                {
                    index_by_id_.erase(entity->id());
                    delete entity;
                }
                else 
                {
                    c.push_back(entity);
                }
            }
            cache_.clear();
            cache_.swap(c);
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("CHECKINGACCOUNT_V1: Exception %s", e.GetMessage().utf8_str());
            return false;
        }

        return true;
    }

    /** Remove the Data record from the database and the memory table (cache) */
    bool remove(Self::Data* entity, wxSQLite3Database* db)
    {
        if (remove(entity->id(), db))
        {
            entity->id(-1);
            return true;
        }

        return false;
    }

    template<typename... Args>
    Self::Data* get_one(const Args& ... args)
    {
        for (auto& [_, item] : index_by_id_)
        {
            if (item->id() > 0 && match(item, args...)) 
            {
                ++ hit_;
                return item;
            }
        }

        ++ miss_;

        return 0;
    }
    
    /**
    * Search the memory table (Cache) for the data record.
    * If not found in memory, search the database and update the cache.
    */
    Self::Data* get(const int64 id, wxSQLite3Database* db)
    {
        if (id <= 0) 
        {
            ++ skip_;
            return nullptr;
        }

        if (auto it = index_by_id_.find(id); it != index_by_id_.end())
        {
            ++ hit_;
            return it->second;
        }
        
        ++ miss_;
        Self::Data* entity = nullptr;
        wxString where = wxString::Format(" WHERE %s = ?", PRIMARY::name().utf8_str());
        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(this->query() + where);
            stmt.Bind(1, id);

            wxSQLite3ResultSet q = stmt.ExecuteQuery();
            if(q.NextRow())
            {
                entity = new Self::Data(q, this);
                cache_.push_back(entity);
                index_by_id_.insert(std::make_pair(id, entity));
            }
            stmt.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().utf8_str(), e.GetMessage().utf8_str());
        }
        
        if (!entity) 
        {
            entity = this->fake_;
            // wxLogError("%s: %d not found", this->name().utf8_str(), id);
        }
 
        return entity;
    }
    /**
    * Search the database for the data record, bypassing the cache.
    */
    Self::Data* get_record(const int64 id, wxSQLite3Database* db)
    {
        if (id <= 0) 
        {
            ++ skip_;
            return nullptr;
        }

        Self::Data* entity = nullptr;
        wxString where = wxString::Format(" WHERE %s = ?", PRIMARY::name().utf8_str());
        try
        {
            wxSQLite3Statement stmt = db->PrepareStatement(this->query() + where);
            stmt.Bind(1, id);

            wxSQLite3ResultSet q = stmt.ExecuteQuery();
            if(q.NextRow())
            {
                entity = new Self::Data(q, this);
            }
            stmt.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().utf8_str(), e.GetMessage().utf8_str());
        }
        
        if (!entity) 
        {
            entity = this->fake_;
            // wxLogError("%s: %d not found", this->name().utf8_str(), id);
        }
 
        return entity;
    }

    /**
    * Return a list of Data records (Data_Set) derived directly from the database.
    * The Data_Set is sorted based on the column number.
    */
    const Data_Set all(wxSQLite3Database* db, const COLUMN col = COLUMN(0), const bool asc = true)
    {
        Data_Set result;
        try
        {
            wxSQLite3ResultSet q = db->ExecuteQuery(col == COLUMN(0) ? this->query() : this->query() + " ORDER BY " + column_to_name(col) + " COLLATE NOCASE " + (asc ? " ASC " : " DESC "));

            while(q.NextRow())
            {
                Self::Data entity(q, this);
                result.push_back(std::move(entity));
            }

            q.Finalize();
        }
        catch(const wxSQLite3Exception &e) 
        { 
            wxLogError("%s: Exception %s", this->name().utf8_str(), e.GetMessage().utf8_str());
        }

        return result;
    }
};

