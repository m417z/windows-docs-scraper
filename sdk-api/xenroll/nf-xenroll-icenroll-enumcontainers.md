# ICEnroll::enumContainers

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **enumContainers** method retrieves the names of containers for the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) specified by the
[ProviderName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_providername) property. This method was first defined in the [ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll) interface.

## Parameters

### `dwIndex` [in]

Specifies the ordinal position of the container whose name will be retrieved. Specify zero for the first container.

### `pbstr` [out]

A pointer to a **BSTR** variable that receives the name of the container. When you have finished using the **BSTR**, free it by calling the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function.

## Return value

### C++

The return value is an **HRESULT**. A value of S_OK indicates success. The value ERROR_NO_MORE_ITEMS is returned when there are no more items.

### VB

The return value is a **String** variable that represents the name of the container. An exception is raised if an error is encountered or when there are no more items.

## Remarks

If the
[ProviderName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_providername) property value has not been set, the default value (usually Microsoft Base Cryptographic Provider) of **ProviderName** as set in the registry, is used.

This method is disabled when the Certificate Enrollment Control is executed as a scripted control.

#### Examples

```cpp
BSTR       bstrCon = NULL;
DWORD      nCon = 0;
HRESULT    hr;

// pEnroll is previously instantiated ICEnroll interface pointer
while ( S_OK == pEnroll->enumContainers(nCon, &bstrCon) )
{
    printf("\t%d) %ws\n", nCon++, bstrCon );
    if ( bstrCon )
    {
        SysFreeString( bstrCon );
        bstrCon = NULL;
    }
}
```

## See also

[CEnroll](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa376007(v=vs.85))

[ICEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll)

[ICEnroll2](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll2)

[ICEnroll3](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll3)

[ICEnroll4](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-icenroll4)

[ProviderName](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-icenroll-get_providername)