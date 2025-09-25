# IMFMediaEngineProtectedContent::SetContentProtectionManager

## Description

Sets the content protection manager (CPM).

## Parameters

### `pCPM` [in]

A pointer to the [IMFContentProtectionManager](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentprotectionmanager) interface, implemented by the caller.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The Media Engine uses the CPM to handle events related to protected content, such as license acquisition.

## See also

[IMFMediaEngineProtectedContent](https://learn.microsoft.com/windows/desktop/api/mfmediaengine/nn-mfmediaengine-imfmediaengineprotectedcontent)