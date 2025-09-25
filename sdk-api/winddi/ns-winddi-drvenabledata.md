# DRVENABLEDATA structure

## Description

The DRVENABLEDATA structure contains a pointer to an array of [DRVFN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvfn) structures and the graphics DDI version number of an NT-based operating system.

## Members

### `iDriverVersion`

Specifies the graphics DDI version number of the NT-based operating system that the driver is targeted for. This member can be set to one of the following values:

| Value | Operating System Version |
| --- | --- |
| DDI_DRIVER_VERSION_NT4 | Windows NT 4.0 |
| DDI_DRIVER_VERSION_SP3 | Windows NT 4.0 Service Pack 3 |
| DDI_DRIVER_VERSION_NT5 | Windows 2000 |
| DDI_DRIVER_VERSION_NT5_01 | Windows XP |
| DDI_DRIVER_VERSION_NT5_01_SP1 | Windows XP Service Pack 1 |

See the Remarks section for more information.

### `c`

Specifies the number of [DRVFN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvfn) structures in the buffer pointed to by the **pdrvfn** member.

### `pdrvfn`

Pointer to a buffer containing an array of [DRVFN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvfn) structures.

## Remarks

To run on these NT-based operating systems versions, the **iDriverVersion** member must be set as follows:

| Windows version | Value of iDriverVersion |
| --- | --- |
| Windows NT 4.0 | **iDriverVersion** == DDI_DRIVER_VERSION_NT4 |
| Windows NT 4.0 SP3 | DDI_DRIVER_VERSION_NT4 <= **iDriverVersion** <= DDI_DRIVER_VERSION_SP3 |
| Windows 2000 | DDI_DRIVER_VERSION_NT4 <= **iDriverVersion** <= DDI_DRIVER_VERSION_NT5 |
| Windows XP | DDI_DRIVER_VERSION_NT4 <= **iDriverVersion** <= DDI_DRIVER_VERSION_NT5_01 |
| Windows XP SP1 | DDI_DRIVER_VERSION_NT4 <= **iDriverVersion** <= DDI_DRIVER_VERSION_NT5_01_SP1 |

As the table shows, a driver can run on any of these operating system versions if **iDriverVersion** is set to DDI_DRIVER_VERSION_NT4, but a driver can run only on Windows XP and later versions of the operating system if **iDriverVersion** is set to DDI_DRIVER_VERSION_NT5_01.

**Note** If a driver implements a *DrvXxx* graphics DDI that is not supported in all versions of Windows, the driver cannot specify a DRVFN entry for that graphics DDI when running on versions of Windows that do not support it. If the driver does specify a DRVFN entry for such a graphics DDI, Windows will reject the driver. The *permedia2* sample demonstrates how to specify different DRVFN structures for different versions of Windows.

## See also

[DRVFN](https://learn.microsoft.com/windows/desktop/api/winddi/ns-winddi-drvfn)

[DrvEnableDriver](https://learn.microsoft.com/windows/desktop/api/winddi/nf-winddi-drvenabledriver)