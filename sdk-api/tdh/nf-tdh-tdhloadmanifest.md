# TdhLoadManifest function

## Description

Loads the manifest used to decode a log file.

## Parameters

### `Manifest` [in]

The full path to the manifest.

## Return value

Returns ERROR_SUCCESS if successful. Otherwise, this function returns one of the following return codes in addition to others.

| Return code | Description |
| --- | --- |
| **ERROR_FILE_NOT_FOUND** | The manifest file was not found at the specified path. |
| **ERROR_INVALID_PARAMETER** | The *Manifest* parameter cannot be **NULL** and the path cannot exceed MAX_PATH. |
| **ERROR_XML_PARSE_ERROR** | The manifest did not pass validation. To determine the validation errors, run the manifest through the message compiler (mc.exe). |

## Remarks

To consume events, TDH requires the provider's manifest. Typically, you decode the log file on a computer that contains the provider. Since the provider includes the manifest as a resource, TDH uses the provider to get the manifest. To decode the log file on a computer that does not contain the provider, you must first use the TraceRpt.exe executable to export the manifest (see the –export switch) from the provider on a computer that does contain the provider. After you have the manifest file, you can decode the log file on a computer that does not contain the provider.

You need to call this function before decoding the first event. For example, you can call this function before calling the [OpenTrace](https://learn.microsoft.com/windows/desktop/ETW/opentrace) function. After processing all the events, call the [TdhUnloadManifest](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhunloadmanifest) function.

## See also
[TdhUnloadManifest](https://learn.microsoft.com/windows/desktop/api/tdh/nf-tdh-tdhunloadmanifest)