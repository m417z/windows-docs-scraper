# IDesktopGadget::RunGadget

## Description

Adds an installed gadget to the desktop.

## Parameters

### `gadgetPath` [in]

Type: **LPCWSTR**

Pointer to the full (absolute) path of a .gadget folder. A gadget that is not packaged with Windows can only be run from one of the two following locations. Installation of the gadget in any other location will cause this method to fail with an access denied error.

**Note** This path should not contain environment variables; the fully expanded path must be provided. [ExpandEnvironmentStrings](https://learn.microsoft.com/windows/desktop/api/rrascfg/nn-rrascfg-ieapproviderconfig) can be used to expand the path to the form required in this parameter.

#### (%ProgramFiles%\Windows Sidebar\Shared Gadgets)

This is the recommended path for non-Microsoft gadget installation, available to all users.

#### (%LOCALAPPDATA%\Microsoft\Windows Sidebar\Gadgets)

This location should be used for a single-user installation of the gadget.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **SCHED_E_ALREADY_RUNNING** | The gadget is already running. |
| **E_INVALIDARG** | An error occurred involving the path of the gadget folder pointed to by *gadgetPath*. |

## Remarks

"Running" a gadget here means that the gadget is added to the desktop.

**RunGadget** can only be called on a gadget that has already been installed to the system. It cannot be called on a gadget that is already running—only one instance of a gadget can be run at any given time through this method.

Because gadget installation has no UI of its own, this method is often run as the last step in the installation process or as part of the first launch of an application that the gadget is associated with. Installation of the gadget to %ProgramFiles%\Windows Sidebar\Shared Gadgets requires administrative privileges. Therefore it is recommended that the installation of the gadget be performed as part of a Microsoft Installer (MSI) installation.

**Important** Applications should not call **RunGadget** without first asking the user for permission. If the choice is given to the user as a check box, that check box should be unselected by default.

The gadget is added to the desktop at a position determined by the system. The caller cannot specify location.

Per-user applications should install their gadgets per-user. Per-machine applications should install their gadgets per-machine. This ensures a unified experience to the user.

#### Examples

The following example shows **IDesktopGadget::RunGadget** in use.

```cpp
HRESULT RunMyGadget(PCWSTR pszGadgetPath)
{
    IDesktopGadget *pDG;

    HRESULT hr = CoCreateInstance(CLSID_DesktopGadget,
                                  NULL,
                                  CLSCTX_INPROC_SERVER,
                                  IID_PPV_ARGS(&pDG));
    if (SUCCEEDED(hr))
    {
        hr = pDG->RunGadget(pszGadgetPath);
        pDG->Release();
    }

    return hr;
}
```