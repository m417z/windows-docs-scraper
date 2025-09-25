# TdhUnloadManifest function

## Description

Unloads the manifest that was loaded by the [TdhLoadManifest](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhloadmanifest) function.

## Parameters

### `Manifest` [in]

The full path to the loaded manifest.

## Return value

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The manifest file was not found at the specified path. |
| **ERROR_INVALID_PARAMETER** | The *Manifest* parameter cannot be **NULL** and the path cannot exceed MAX_PATH. |
| **ERROR_XML_PARSE_ERROR** | The manifest did not pass validation. To determine the validation errors, run the manifest through the message compiler (mc.exe). |

## Remarks

You must call this function after processing all the events. For example, you can call this function after calling [CloseTrace](https://learn.microsoft.com/windows/desktop/ETW/closetrace).

## See also
[TdhLoadManifest](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhloadmanifest)