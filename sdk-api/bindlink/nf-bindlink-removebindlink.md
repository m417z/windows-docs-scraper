## Description

This API allows a user to remove a link that was previously created by calling [CreateBindLink](https://learn.microsoft.com/windows/win32/api/bindlink/nf-bindlink-createbindlink).

## Parameters

### `virtualPath`

The virtual path for which the bind link is to be removed.

## Return value

## Remarks

This API will fail if the user does not have Administrator privileges, or if the user does not have permission to access the virtual path, or if the link being deleted is the ancestor of an existing link. The API will also fail if the link doesn’t exist or due to another internal error. If an app is in the middle of traversing the virtual path while **RemoveBindLink** is called, the resulting behavior will depend on where each of the threads are in the process (i.e., this is a race between the link being deleted and the file/directory being accessed).

Note that nested links must be removed in deepest-first order. This means the deepest virtual path must be removed before ancestor virtual paths can be removed. Unrelated services that create the links and remove the links are expected to be respectful of each other's personal space and limit their mappings to paths under their control.

## Examples

The following example shows how a user can remove a previously created link on `C:\\test`.

```cpp
#include <iostream>
#include <wil\resource.h>
#include <bindlink.h>

int wmain(int argc, wchar_t* argv[])
{
    constexpr PCWSTR virtPath = L"C:\test";
    HRESULT hr = S_OK;

    hr = RemoveBindLink(virtPath);

    if(FAILED(hr))
    {
        std::cerr << "RemoveBindLink Failed with Err: " << hr;
        return hr;
    }

    std::cout << "Link Deleted!\n";
}
```

For a full example of how to use the **CreateBindLink** and **RemoveBindLink** APIs, see the [bind link example](https://learn.microsoft.com/windows/win32/bindlink/bindlink-example) page.

## See also

[CreateBindLink](https://learn.microsoft.com/windows/win32/api/bindlink/nf-bindlink-createbindlink)