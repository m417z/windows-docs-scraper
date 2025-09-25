# SHAssocEnumHandlersForProtocolByApplication function

## Description

Gets an enumeration interface that provides access to handlers associated with a given protocol.

## Parameters

### `protocol` [in]

Type: **PCWSTR**

Pointer to a string that specifies the protocol.

### `riid` [in]

Type: **REFIID**

A reference to the IID of the interface to retrieve through *enumHandlers*, typically IID_IEnumAssocHandlers.

### `enumHandlers` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IEnumAssocHandlers](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumassochandlers).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

It is recommended that you use the **IID_PPV_ARGS** macro, defined in Objbase.h, to package the *riid* and *enumHandlers* parameters. This macro provides the correct IID based on the interface pointed to by the value in *enumHandlers*, which eliminates the possibility of a coding error.