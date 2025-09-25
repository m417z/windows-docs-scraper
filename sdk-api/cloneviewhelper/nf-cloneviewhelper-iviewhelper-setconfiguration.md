# IViewHelper::SetConfiguration

## Description

The **SetConfiguration** method passes in display data (display modes and topology data) to the underlying user-mode display driver that the driver should set.

## Parameters

### `pIStream` [in, optional]

[in] A pointer to an **IStream** interface. The **IStream** object contains display modes and topology data that are formatted by using the data structures in the *Cloneviewhelper.h* header file. When the **Release** method of **IStream** is called, the memory that backs the **IStream** is freed. TMM will call **Release** on the **IStream** interface pointer if **SetConfiguration** returns an error result. Otherwise, the user-mode display driver should call **Release**. **Release** is called to free the memory that was allocated to store the view information. For more information about **IStream**, see the Microsoft Windows SDK documentation.

### `pulStatus` [out]

[out] A pointer to a ULONG that receives the driver's status after the driver performs the configuration that TMM passed in. The status can be set to one of the following values.

| Value | Meaning |
| --- | --- |
| SETCONFIGURATION_STATUS_APPLIED (0) | The driver applied the configuration that TMM passed in. |
| SETCONFIGURATION_STATUS_ADDITIONAL (1) | The driver applied the configuration that TMM passed in along with additional proprietary hardware-vendor settings. |
| SETCONFIGURATION_STATUS_OVERRIDDEN (2) | The driver overrode the configuration that TMM passed in and applied proprietary hardware-vendor settings. |

## Return value

The **SetConfiguration** method returns one of the following values:

| Return code | Description |
| --- | --- |
| **S_OK** | **SetConfiguration** successfully set up display data. |
| **E_POINTER** | The *pIStream* parameter is set to **NULL**. |
| **E_ABORT** | The driver failed to apply settings. In this situation, TMM will resume control and apply settings through a call to the Win32 **ChangeDisplaySettingsEx** function and the [IViewHelper::SetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568174(v=vs.85)) method. For more information about **ChangeDisplaySettingsEx**, see the Windows SDK documentation. |

## Remarks

After **SetConfiguration** passes display data to the underlying user-mode display driver, the driver can modify or fold in new data before setting the display.

**SetConfiguration** is called when TMM must change the display settings and topology to match a known state that was last recorded by TMM.

The following data structures are used to format the display modes and topology data that the **IStream** object that the *pIStream* parameter points to contains:

* [Sources](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-sources)
* [Adapter](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-adapter)
* [Adapters](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-adapters)
* [DisplayMode](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-displaymode)
* [DisplayModes](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-displaymodes)

These structures are defined in the *Cloneviewhelper.h*.

## See also

[Adapter](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-adapter)

[Adapters](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-adapters)

[DisplayMode](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-displaymode)

[DisplayModes](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-displaymodes)

[IViewHelper::SetActiveTopology](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568174(v=vs.85))

[Sources](https://learn.microsoft.com/windows/desktop/api/cloneviewhelper/ns-cloneviewhelper-sources)