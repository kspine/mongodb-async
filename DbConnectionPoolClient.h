#ifndef MONGODB_ASYNC_CONNECTIONPOOLCLIENT_H
#define MONGODB_ASYNC_CONNECTIONPOOLCLIENT_H

#include "BaseHeader.h"
#include "DbConnectionPool.h"

using namespace std::placeholders;

class DbConnectionPoolClient {
    io_service& mIoService;
    DbConnectionPool& mDbConnectionPool;
public:
    void insertOne(string &&collection, document_ptr &&document, InsertOneCompletionHandler callback) {
        mDbConnectionPool.insertOne(mIoService, collection, document, callback);
    }
    void insertMany(string &&collection, document_vector_ptr &&documents, InsertManyCompletionHandler callback) {
        mDbConnectionPool.insertMany(mIoService, collection, documents, callback);
    }
    void find(string &&collection, document_ptr &&query, FindCompletionHandler callback) {
        mDbConnectionPool.find(mIoService, collection, query, callback);
    }
    void findOne(string &&collection, document_ptr &&query, FindOneCompletionHandler callback) {
        mDbConnectionPool.findOne(mIoService, collection, query, callback);
    }
    void updateOne(string&& collection, document_ptr&& query, UpdateOneCompletionHandler callback) {
        mDbConnectionPool.updateOne(mIoService, collection, query, callback);
    }
    void updateMany(string&& collection, document_ptr&& query, UpdateManyCompletionHandler callback) {
        mDbConnectionPool.updateMany(mIoService, collection, query, callback);
    }
    void deleteOne(string&& collection, document_ptr&& query, DeleteOneCompletionHandler callback) {
        mDbConnectionPool.deleteOne(mIoService, collection, query, callback);
    }
    void deleteMany(string&& collection, document_ptr&& query, DeleteManyCompletionHandler callback) {
        mDbConnectionPool.deleteMany(mIoService, collection, query, callback);
    }
    DbConnectionPoolClient(io_service &mIoService, DbConnectionPool& cp)
            : mIoService(mIoService), mDbConnectionPool(cp) {
    }
};

#endif //MONGODB_ASYNC_CONNECTIONPOOLCLIENT_H