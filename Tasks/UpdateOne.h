#ifndef MONGODB_ASYNC_UPDATEONE_H
#define MONGODB_ASYNC_UPDATEONE_H

#include "../BaseHeader.h"
#include "../MongoDbHeader.h"
#include "../TaskContext.h"

typedef function<void(bool err)> UpdateOneCompletionHandler;

class UpdateOneTask: public TaskContext {
public:
    string collection;
    document_ptr query;
    document_ptr document;
    UpdateOneCompletionHandler completionHandler;
    UpdateOneTask(io_service& targetService, string collection, document_ptr query, document_ptr document, UpdateOneCompletionHandler completionHandler)
            : TaskContext(targetService),
              collection(collection),
              query(query),
              document(document),
              completionHandler(completionHandler) { }
};

#endif //MONGODB_ASYNC_UPDATEONE_H
