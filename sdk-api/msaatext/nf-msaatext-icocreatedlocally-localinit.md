# ICoCreatedLocally::LocalInit

## Description

Implemented by clients to return information about the local object.

**Note** Active Accessibility Text Services is deprecated. Please see
[Microsoft Windows Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) for more information on advanced text input and natural language technologies.

## Parameters

### `punkLocalObject` [in]

Type: **IUnknown***

A pointer to the server object.

### `riidParam` [in]

Type: **REFIID**

An optional interface parameter that is passed to the new helper object. This parameter specifies an interface identifier.

### `punkParam` [in]

Type: **IUnknown***

An optional interface parameter that is passed to the new helper object. This parameter specifies the interface pointer.

### `varParam` [in]

Type: **VARIANT**

An optional interface parameter that is passed to the new helper object.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK. If not successful, returns a standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).