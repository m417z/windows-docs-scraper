## Syntax

```cpp
typedef struct _DEV_QUERY_RESULT_ACTION_DATA {
  DEV_QUERY_RESULT_ACTION          Action;
  union _DEV_QUERY_RESULT_UPDATE_PAYLOAD {
    DEV_QUERY_STATE State;
    DEV_OBJECT      DeviceObject;
  } Data;
} DEV_QUERY_RESULT_ACTION_DATA, *PDEV_QUERY_RESULT_ACTION_DATA;
```

## Description

Provides information to the [PDEV_QUERY_RESULT_CALLBACK](https://learn.microsoft.com/windows/win32/api/devquery/nc-devquery-pdev_query_result_callback) callback function.

## Members

### `Action`

A value from the [DEV_QUERY_RESULT_ACTION](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_result_action) enumeration specifying the type of action being performed.

### `Data`

A value from the *_DEV_QUERY_RESULT_UPDATE_PAYLOAD* union.

### `Data.State`

A value from the [DEV_QUERY_STATE](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_state) enumeration specifying the current state of the query. This member is valid only if *Action* is equal to [DevQueryResultStateChange](https://learn.microsoft.com/windows/win32/api/devquerydef/ne-devquerydef-dev_query_result_action).

### `Data.DeviceObject`

A [DEV_OBJECT](https://learn.microsoft.com/windows/win32/api/devquerydef/ns-devquerydef-dev_object) structure associated with the query result. This member is only valid if *Action* is equal to **DevQueryResultAdd**, **DevQueryResultUpdate**, or **DevQueryResultRemove**. The following table specifies how the *DevObject* field should be interpreted, depending on the value of the *Action* field.

| Action value | Interpretation of *DeviceObject* |
|--------------|------------------------------|
| **DevQueryResultAdd** | *DeviceObject* represents a new object being added to the query’s result set due to it meeting the criteria of the query’s filter parameters. *DeviceObject* will contain a list of properties for all properties requested by the query. |
| **DevQueryResultUpdate** | *DeviceObject* represents an object already in the query’s result set that has had a requested property changed. The property list in *DeviceObject* will provide the properties that have changed. |
| **DevQueryResultRemove** | *DeviceObject* represents an object that is being removed from the query’s result set due to it no longer meeting the criteria of the query’s filter parameters. |

### `_DEV_QUERY_RESULT_UPDATE_PAYLOAD`

The union containing the the state or object associated with the action.

## Remarks

## See also