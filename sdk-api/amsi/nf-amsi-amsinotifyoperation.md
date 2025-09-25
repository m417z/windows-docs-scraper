## Description

Sends to the antimalware provider a notification of an arbitrary operation. The notification doesn't imply the request of an antivirus scan. Rather, **IAntimalwareProvider2::Notify** is designed to provide a quick and lightweight mechanism to communicate to the antimalware provider that an event has taken place. In general, the antimalware provider should process the notification, and return to the caller as quickly as possible.

## Parameters

### `amsiContext`

Type: \_In\_ **HAMSICONTEXT**

The handle (of type **HAMSICONTEXT**) that was initially received from [AmsiInitialize](https://learn.microsoft.com/windows/win32/api/amsi/nf-amsi-amsiinitialize).

### `buffer`

Type: \_In\_reads\_bytes\_(length) **[PVOID](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The buffer that contains the notification data.

### `length`

Type: \_In\_ **[ULONG](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The length, in bytes, of the data to be read from *buffer*.

### `contentName`

Type: \_In\_opt\_ **[LPCWSTR](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The filename, URL, unique script ID, or similar of the content being scanned.

### `result`

Type: \_Out\_ **[AMSI_RESULT](https://learn.microsoft.com/windows/win32/api/amsi/ne-amsi-amsi_result)\***

The result of the scan.

You should use [AmsiResultIsMalware](https://learn.microsoft.com/windows/win32/api/amsi/nf-amsi-amsiresultismalware) to determine whether the content should be blocked.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

## See also