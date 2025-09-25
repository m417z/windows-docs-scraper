# IWDFNamedPropertyStore::GetNamedValue

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetNamedValue** method retrieves the value of a property.

## Parameters

### `pszName` [in]

A pointer to a null-terminated string that contains the name of the property.

### `pv` [out]

A pointer to a variable that receives the value for the property.

## Return value

**GetNamedValue** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The **GetNamedValue** method allocates memory for a string in the [PROPVARIANT](https://learn.microsoft.com/windows/win32/api/propidlbase/ns-propidlbase-propvariant) structure pointed to by the *pv* parameter. The caller must then free this memory by calling the [PropVariantClear](https://learn.microsoft.com/windows/win32/api/propidl/nf-propidl-propvariantclear) function, as shown in the following snippet:

```
hr = pPropStore->GetNamedValue(L"Host", &val);
...
PropVariantClear(&val);
```

If the caller does not free the memory, a memory leak may result.

The following variant types are supported for property values. The following table shows the variant type that is returned regardless of the original variant type.

| Variant type | Variant type retrieved |
| --- | --- |
| VT_BSTR | While clients read a string value, the value is returned as VT_LPWSTR regardless of the original variant type that was used to write the value. |
| VT_LPWSTR |
| VT_LPSTR |
| VT_I1 | While clients read an integer value, the value is returned as VT_UI4 regardless of the original variant type that was used to write the value. |
| VT_UI1 |
| VT_I2 |
| VT_UI2 |
| VT_I4 |
| VT_UI4 |
| VT_UINT |
| VT_BLOB | The binary value is returned as VT_BLOB. |
| VT_VECTOR | VT_LPWSTR | The string array is returned as VT_VECTOR | VT_LPWSTR |

A string that contains environment variables is expanded on read.

For more information, see [Using the Registry in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-the-registry-in-umdf-1-x-drivers).

## See also

[IWDFNamedPropertyStore](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfnamedpropertystore)

[PROPVARIANT](https://learn.microsoft.com/windows/win32/api/propidlbase/ns-propidlbase-propvariant)

[PropVariantClear](https://learn.microsoft.com/windows/win32/api/propidl/nf-propidl-propvariantclear)