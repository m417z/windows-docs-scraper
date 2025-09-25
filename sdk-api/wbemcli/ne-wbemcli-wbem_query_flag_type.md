# WBEM_QUERY_FLAG_TYPE enumeration

## Description

Contains flags used to define a query or enumerator.

## Constants

### `WBEM_FLAG_DEEP:0`

Include the specified class and all subclasses.

### `WBEM_FLAG_SHALLOW:1`

Include only the specified class, not any subclasses.

### `WBEM_FLAG_PROTOTYPE:2`

Used for prototyping. It does not execute the query and instead returns an object that looks like a typical result object.

## See also

[IWbemServices::CreateClassEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createclassenum)

[IWbemServices::CreateClassEnumAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createclassenumasync)

[IWbemServices::CreateInstanceEnum](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenum)

[IWbemServices::CreateInstanceEnumAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-createinstanceenumasync)

[IWbemServices::ExecQuery](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execquery)

[IWbemServices::ExecQueryAsync](https://learn.microsoft.com/windows/desktop/api/wbemcli/nf-wbemcli-iwbemservices-execqueryasync)