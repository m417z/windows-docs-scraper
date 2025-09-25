# DsCrackNamesA function

## Description

The **DsCrackNames** function
converts an array of directory service object names from one format to another. Name conversion enables client applications to map between the
multiple names used to identify various directory service objects. For example,
user objects can be identified by SAM account names (*Domain*\*UserName*), user
principal name (*UserName*@*Domain*.com), or distinguished name.

## Parameters

### `hDS` [in]

Contains a directory service handle obtained from either the
[DSBind](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbinda) or
[DSBindWithCred](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsbindwithcreda) function. If *flags* contains
[DS_NAME_FLAG_SYNTACTICAL_ONLY](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_flags), *hDS* can be
**NULL**.

### `flags` [in]

Contains one or more of the [DS_NAME_FLAGS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_flags) values used to determine how the name syntax will be cracked.

### `formatOffered` [in]

Contains one of the [DS_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_format) values that identifies the format of the input names.

The **DS_LIST_NCS** value can also be passed for this parameter. This causes **DsCrackNames** to return the distinguished names of all naming contexts in the current forest. The *formatDesired* parameter is ignored. *cNames* must be at least one and all strings in *rpNames* must have a length greater than zero characters. The contents of the *rpNames* strings is ignored.

**Note** **DS_LIST_NCS** is not defined in a published header file. To use this value, define it in the exact format shown below.

```cpp
#ifndef DS_LIST_NCS
    #define DS_LIST_NCS 0xfffffff6
#endif
```

### `formatDesired` [in]

Contains one of the [DS_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_format) values that identifies the format of the output names. The **DS_SID_OR_SID_HISTORY_NAME** value is not supported.

### `cNames` [in]

Contains the number of elements in the *rpNames* array.

### `rpNames` [in]

Pointer to an array of pointers to null-terminated strings that contain names to be converted.

### `ppResult` [out]

Pointer to a **PDS_NAME_RESULT** value that receives a [DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta) structure
that contains the converted names. The caller must free this memory, when it is no longer required, by calling [DsFreeNameResult](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreenameresulta).

## Return value

Returns a Win32 error value, an RPC error value, or one of the following.

## Remarks

The success of the name conversion request depends on where the
client is bound. Clients bind to specific instances of the directory service
using some variant of **DsBind**. If bound to a
global catalog, the scope of the name mapping is the entire forest. If not bound to a global catalog, the scope of the name mapping is the domain not
covered by a global catalog for that domain controller. If not bound to a
global catalog and a name is not found, but the input name unambiguously
identifies its domain and this domain is in the forest, then the return data
identifies the DNS domain name for the domain of interest. Clients are expected
to use this data to bind to the correct domain controller or global
catalog and call **DsCrackNames** again with the new bind handle.

The return value from **DsCrackNames** indicates errors such as invalid
parameters or insufficient memory. However, problems in converting individual
names are reported in the **status** member of the [DS_NAME_RESULT_ITEM](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_result_itema) structure returned for each input name.

**Note** Do not confuse the values of the format elements of
the *formatOffered* parameter used by the
**DsCrackNames** function with the similarly
named format elements as defined in the [ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum) enumeration used by the [IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate) interface. The
two sets of element formats are not equivalent and are not interchangeable.

> [!NOTE]
> The ntdsapi.h header defines DsCrackNames as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[ADS_NAME_TYPE_ENUM](https://learn.microsoft.com/windows/win32/api/iads/ne-iads-ads_name_type_enum)

[DS_NAME_FLAGS](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_flags)

[DS_NAME_FORMAT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ne-ntdsapi-ds_name_format)

[DS_NAME_RESULT](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_resulta)

[DS_NAME_RESULT_ITEM](https://learn.microsoft.com/windows/desktop/api/ntdsapi/ns-ntdsapi-ds_name_result_itema)

[Domain Controller and Replication Management Functions](https://learn.microsoft.com/windows/desktop/AD/dc-and-replication-management-functions)

[DsFreeNameResult](https://learn.microsoft.com/windows/desktop/api/ntdsapi/nf-ntdsapi-dsfreenameresulta)

[IADsNameTranslate](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iadsnametranslate)