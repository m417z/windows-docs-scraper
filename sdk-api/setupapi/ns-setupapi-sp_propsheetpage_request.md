# SP_PROPSHEETPAGE_REQUEST structure

## Description

An SP_PROPSHEETPAGE_REQUEST structure can be passed as the first parameter (*lpv*) to the **ExtensionPropSheetPageProc** entry point in the [SetupAPI](https://learn.microsoft.com/windows-hardware/drivers/install/setupapi) DLL. **ExtensionPropSheetPageProc** is used to retrieve a handle to a specified property sheet page.

For information about **ExtensionPropSheetPageProc** and related functions, see the Microsoft Windows SDK documentation.

## Members

### `cbSize`

The size, in bytes, of the SP_PROPSHEETPAGE_REQUEST structure.

### `PageRequested`

The property sheet page to add to the property sheet. Can be one of the following values:

#### SPPSR_SELECT_DEVICE_RESOURCES

Specifies the Resource Selection page supplied by the SetupAPI DLL.

#### SPPSR_ENUM_BASIC_DEVICE_PROPERTIES

Specifies a page that is supplied by the device's BasicProperties32 provider. That is, an installer or other component that supplied page(s) in response to a [DIF_ADDPROPERTYPAGE_BASIC](https://learn.microsoft.com/windows-hardware/drivers/install/dif-addpropertypage-basic) installation request.

#### SPPSR_ENUM_ADV_DEVICE_PROPERTIES

Specifies a page that is supplied by the class and/or the device's EnumPropPages32 provider. That is, an installer or other component that supplied page(s) in response to a [DIF_ADDPROPERTYPAGE_ADVANCED](https://learn.microsoft.com/windows-hardware/drivers/install/dif-addpropertypage-advanced) installation request.

### `DeviceInfoSet`

The handle for the device information set that contains the device being installed.

### `DeviceInfoData`

A pointer to an [SP_DEVINFO_DATA](https://learn.microsoft.com/windows/desktop/api/setupapi/ns-setupapi-sp_devinfo_data) structure for the device being installed.

## Remarks

The component that is retrieving the property pages calls SetupAPI's **ExtensionPropSheetPageProc** function and passes in a pointer to a SP_PROPSHEETPAGE_REQUEST structure, the address of their **AddPropSheetPageProc**  function, and some private data. The property sheet provider calls the **AddPropSheetPageProc** routine for each property sheet it provides.

The following code excerpt shows how to retrieve one page, the SetupAPI's Resource Selection page:

```
{
    DWORD Err;
    HINSTANCE hLib;
    FARPROC PropSheetExtProc;
    HPROPSHEETPAGE hPages[2];
    .
    .
    .
        if(!(hLib = GetModuleHandle(TEXT("setupapi.dll")))) {
            return GetLastError();
        }

        if(!(PropSheetExtProc = GetProcAddress(hLib,
                 "ExtensionPropSheetPageProc"))) {
            Err = GetLastError();
            FreeLibrary(hLib);
            return Err;
        }

        PropPageRequest.cbSize = sizeof(SP_PROPSHEETPAGE_REQUEST);
        PropPageRequest.PageRequested  =
            SPPSR_SELECT_DEVICE_RESOURCES;
        PropPageRequest.DeviceInfoSet  = DeviceInfoSet;
        PropPageRequest.DeviceInfoData = DeviceInfoData;

        if(!PropSheetExtProc(&PropPageRequest,
                AddPropSheetPageProc, &hPages[1])) {
            Err = ERROR_INVALID_PARAMETER;
            FreeLibrary(hLib);
            return Err;
        }
        .
        .
        .
}
```

The **AddPropSheetPageProc** for the previous excerpt would be something like the following:

```
BOOL
CALLBACK
AddPropSheetPageProc(
    IN HPROPSHEETPAGE hpage,
    IN LPARAM lParam
   )
{
    *((HPROPSHEETPAGE *)lParam) = hpage;
    return TRUE;
}
```

## See also

[DIF_ADDPROPERTYPAGE_ADVANCED](https://learn.microsoft.com/windows-hardware/drivers/install/dif-addpropertypage-advanced)

[DIF_ADDPROPERTYPAGE_BASIC](https://learn.microsoft.com/windows-hardware/drivers/install/dif-addpropertypage-basic)