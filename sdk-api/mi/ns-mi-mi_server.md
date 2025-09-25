# MI_Server structure

## Description

This structure defines default function tables
for all types: Context, Instance, PropertySet, and Filter.

## Members

### `serverFT`

Pointer to an **MI_Server** function table.

### `contextFT`

Pointer to [MI_Context](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_context) function table.

### `instanceFT`

Pointer to [MI_Instance](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_instance) function table.

### `propertySetFT`

Pointer to [MI_PropertySet](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_propertyset) function table.

### `filterFT`

Pointer to [MI_Filter](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_filter) function table.