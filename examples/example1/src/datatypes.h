#ifndef NGREST_DB_EXAMPLE_ENTITIES_H
#define NGREST_DB_EXAMPLE_ENTITIES_H

#include <string>

#include <ngrest/common/Nullable.h>

namespace ngrest {
namespace example {

// *table: users
struct User
{
    // *pk: true
    // *autoincrement: true
    int id;

    std::string name;

    // *unique: true
    // *type: varchar(64)
    std::string email;

    // *type: timestamp
    // *default: CURRENT_TIMESTAMP
    // *ignoreOnInsert: true
    std::string registered;
};

// *table: groups
struct Group
{
    // *pk: true
    // *autoincrement: true
    int id;

    std::string name;

    Nullable<std::string> comment;
};

// *table: users_to_groups
struct UserToGroup
{
    // *pk: true
    // *autoincrement: true
    int id;

    // *fk: users id
    // *onUpdate: cascade
    // *onDelete: cascade
    int userId;

    // *fk: groups id
    // *key: usertogroup_group_fk
    // *onUpdate: cascade
    // *onDelete: cascade
    int groupId;
};

} // namespace example
} // namespace ngrest

#endif // NGREST_DB_EXAMPLE_ENTITIES_H
