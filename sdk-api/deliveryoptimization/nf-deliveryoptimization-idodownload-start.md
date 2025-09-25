## Description

Starts or resumes a download, passing optional ranges as a pointer to [DO_DOWNLOAD_RANGES_INFO](https://learn.microsoft.com/windows/win32/api/deliveryoptimization/ns-deliveryoptimization-do_download_ranges_info) structure.

## Parameters

### `ranges`

Optional. A pointer to a [DO_DOWNLOAD_RANGES_INFO](https://learn.microsoft.com/windows/win32/api/deliveryoptimization/ns-deliveryoptimization-do_download_ranges_info) structure (to download only specific ranges of the file). The value passed here indicates whether the download is for the entire file or partial ranges within the file or simply to resume the download without changing the ranges info. A request to download the entire file is indicated by passing a pointer to an empty DO_DOWNLOAD_RANGES_INFO structure, that is, with its RangeCount member set to zero. A request to download a partial file is indicated by passing a pointer to a non-empty DO_DOWNLOAD_RANGES_INFO structure. Passing `nullptr` is allowed only when download has already been started once before with empty/non-empty ranges, and indicates download must be resumed without any changes to the ranges requested.

## Return value

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes) [error code](https://learn.microsoft.com/windows/win32/com/com-error-codes-10).

## Remarks

## See also