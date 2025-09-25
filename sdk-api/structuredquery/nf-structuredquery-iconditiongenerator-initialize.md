# IConditionGenerator::Initialize

## Description

Resets all states of the interface to default values and retrieves any necessary information from the schema.

## Parameters

### `pSchemaProvider` [in]

Type: **[ISchemaProvider](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-ischemaprovider)***

Pointer to the schema to be used.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[CONDITION_CREATION_OPTIONS](https://learn.microsoft.com/windows/desktop/api/structuredquery/ne-structuredquery-condition_creation_options)

[CONDITION_OPERATION](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_operation)

[CONDITION_TYPE](https://learn.microsoft.com/windows/win32/api/structuredquerycondition/ne-structuredquerycondition-condition_type)

[ICondition](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition)

[ICondition2](https://learn.microsoft.com/windows/desktop/api/structuredquerycondition/nn-structuredquerycondition-icondition2)

[IConditionFactory](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditionfactory)

[IConditionGenerator](https://learn.microsoft.com/windows/desktop/api/structuredquery/nn-structuredquery-iconditiongenerator)

**Reference**