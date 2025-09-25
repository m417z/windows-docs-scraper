# MI_Class structure

## Description

Represents the schema of an instance.

## Members

### `ft`

Pointer to **MI_Class** function table.

### `classDecl`

Pointer to the class declaration.

### `namespaceName`

The namespace name.

### `serverName`

The server name.

### `reserved`

Reserved for internal use.

## Remarks

The **MI_Class** object represents the schema of an instance. Classes can be retrieved from the server, and instances can be queried for the **MI_Class** object. Use the **MI_Class** APIs rather than navigating the structures themselves.