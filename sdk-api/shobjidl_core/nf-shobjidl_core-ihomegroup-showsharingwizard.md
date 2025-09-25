# IHomeGroup::ShowSharingWizard

## Description

Displays a wizard that allows a user to create a Home Group, and then retrieves the sharing options that the user selected through the wizard.

## Parameters

### `owner` [in]

Type: **HWND**

Handle of the owner window of the wizard, used for notifications. This value can be **NULL**.

### `sharingchoices` [out]

Type: **HOMEGROUPSHARINGCHOICES***

Pointer to a value that, when this method returns successfully, receives one or more of the following values that indicate the libraries and devices chosen through the wizard to be shared with the Home Group.

#### HGSC_NONE (0x00000000)

0x00000000. None of the Home Group options were selected

#### HGSC_MUSICLIBRARY (0x00000001)

0x00000001. The Music library was selected to be shared with the Home Group.

#### HGSC_PICTURESLIBRARY (0x00000002)

0x00000002. The Pictures library was selected to be shared with the Home Group..

#### HGSC_VIDEOSLIBRARY (0x00000004)

0x00000004. The Videos library was selected to be shared with the Home Group.

#### HGSC_DOCUMENTSLIBRARY (0x00000008)

0x00000008. The Documents library was selected to be shared with the Home Group.

#### HGSC_PRINTERS (0x00000010)

0x00000010. Installed printer devices were selected to be shared with the Home Group.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or a standard error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **ERROR_CANCELLED** | The user canceled the wizard. Use [HRESULT_FROM_WIN32](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-hresult_from_win32) to extract this error code. |
| **E_UNEXPECTED** | The computer is not joined to a Home Group or the network or Home Group is not in a state that allows sharing (such as not being connected to the network or having another sharing operation in progress). |
| **E_NOINTERFACE** | The method was launched from a multithreaded apartment (MTA) thread. |
| **E_INVALIDARG** | The *sharingchoices* parameter is **NULL**. |

## Remarks

This method must be called from a single-threaded apartment (STA) thread.

#### Examples

The following code shows an example use of **ShowSharingWizard**.

```cpp
HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
if (SUCCEEDED(hr))
{
    IHomeGroup *phg;

    hr = CoCreateInstance(CLSID_HomeGroup, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&phg));
    if (SUCCEEDED(hr))
    {
        HOMEGROUPSHARINGCHOICES sharingchoices;

        hr = phg->ShowSharingWizard(NULL, &sharingchoices);
        if (SUCCEEDED(hr))
        {
            \\ The user selected to share.

            if (sharingchoices & HGSC_MUSICLIBRARY)
            {
                \\ Music
            }
            if (sharingchoices & HGSC_PICTURESLIBRARY)
            {
                \\ Pictures
            }
            if (sharingchoices & HGSC_VIDEOSLIBRARY)
            {
                \\ Videos
            }
            if (sharingchoices & HGSC_DOCUMENTSLIBRARY)
            {
                \\ Documents
            }
            if (sharingchoices & HGSC_PRINTERS)
            {
                \\ Printers
            }
        }
        phg->Release();
    }
    CoUninitialize();
}
```