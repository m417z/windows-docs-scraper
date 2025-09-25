# RoGetActivationFactory function

## Description

Gets the activation factory for the specified runtime class.

## Parameters

### `activatableClassId` [in]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)**

The ID of the activatable class.

### `iid` [in]

Type: **REFIID**

The reference ID of the interface.

### `factory` [out]

Type: **void****

The activation factory.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.