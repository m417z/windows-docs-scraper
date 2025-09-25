# IDiscMaster2::get_Item

## Description

Retrieves the unique identifier of the specified disc device.

## Parameters

### `index` [in]

Zero-based index of the device whose unique identifier you want to retrieve.

The index value can change during PNP activity when devices are added or removed from the computer, or across boot sessions.

### `value` [out]

String that contains the unique identifier of the disc device associated with the specified index.

## Return value

S_OK is returned on success, but other success codes may be returned as a result of implementation. The following error codes are commonly returned on operation failure, but do not represent the only possible error values:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One or more arguments are not valid.<br><br>Value: 0x80070057 |
| **E_POINTER** | Pointer is not valid.<br><br>Value: 0x80004003 |
| **E_OUTOFMEMORY** | Failed to allocate the required memory.<br><br>Value: 0x8007000E |

## Remarks

To enumerate all identifiers, call the [IDiscMaster2::get__NewEnum](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscmaster2-get__newenum) method.

The following sample demonstrates how to re-enumerate optical drives in order to accurately account for drives added or removed after the initial creation of the [IDiscMaster2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscmaster2) object. This is accomplished via the **IDiscMaster2::get_Item** and [IDiscMaster2::get_Count](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscmaster2-get_count) methods:

```cpp
#include <windows.h>
#include <tchar.h>
#include <imapi2.h>
#include <objbase.h>
#include <stdio.h>

#pragma comment(lib, "ole32.lib")
#pragma comment(lib, "user32.lib")

int __cdecl _tmain(int argc, TCHAR* argv[])
{
    BSTR           bstrDeviceName;
    HRESULT        hr = S_OK;
    BOOL           bComInitialised;
    IDiscMaster2*  discMaster;
    UINT           iCounter = 0;
    LONG           lValue = 0;

    bComInitialised = SUCCEEDED(CoInitializeEx(0, COINIT_MULTITHREADED));

    // Create an object of IDiscMaster2
    if (SUCCEEDED(hr)){
        CoCreateInstance(
            CLSID_MsftDiscMaster2,
            NULL, CLSCTX_ALL,
            IID_PPV_ARGS(&discMaster)
        );

        if(FAILED(hr)){
            _tprintf(TEXT("\nUnsuccessful in creating an instance of CLSID_MsftDiscMaster2.\n\nError returned: 0x%x\n"), hr);
            return 0;
        }
    }
    //
    // Loop twice and get the optical drives attached to the system,
    // first time just get the current configuration and second time
    // prompt the user to change the configuration and then get the
    // altered configuration.
    //
    do{
        // Get the number of drives
        if (SUCCEEDED(hr)){
            hr = discMaster->get_Count(&lValue);
            if (SUCCEEDED(hr)){
                _tprintf(TEXT("\nTotal number of drives = %d\n"), lValue);
            }
        }

        // Print all the optical drives attached to the system
        if (SUCCEEDED(hr)){
            for(LONG iCount = 0; iCount < lValue; iCount++) {
                hr = discMaster->get_Item(iCount, &bstrDeviceName);
                _tprintf(TEXT("\nUnique identifier of the disc device associated with index %d is: %s\n"), iCount, bstrDeviceName);
            }
        }

        // Prompt the user to unhook or add drives
        if (iCounter < 1){
            MessageBox(NULL,TEXT("Please un-hook or add drives and hit OK"), TEXT("Manual Action"), MB_OK);
            _tprintf(TEXT("\nGetting the altered configuration ... \n"));
        }
        iCounter++;
    }while(iCounter < 2);

    discMaster->Release();
    CoUninitialize();
    bComInitialised = FALSE;

    return 0;

```

## See also

[IDiscMaster2](https://learn.microsoft.com/windows/desktop/api/imapi2/nn-imapi2-idiscmaster2)

[IDiscMaster2::get_Count](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscmaster2-get_count)

[IDiscRecorder2::InitializeDiscRecorder](https://learn.microsoft.com/windows/desktop/api/imapi2/nf-imapi2-idiscrecorder2-initializediscrecorder)