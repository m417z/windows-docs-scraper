# GetMediaExtensionCommunicationFactory function

## Description

Creates a communication factory for registering a media extension.

## Parameters

### `factory` [out]

The communication factory.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use this API to create and hold a reference count on the communication factory. Once the call to **RegisterMediaExtensionForAppService** has been made the reference count on the communication factory can be released.