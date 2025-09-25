# UPSInit function

## Description

The **UPSInit** function initializes a UPS minidriver, opens communication to the UPS unit, updates the registry, and causes the minidriver to start monitoring the UPS unit.

## Return value

The **UPSInit** function returns one of the following DWORD values:

| Return code | Description |
| --- | --- |
| **UPS_INITOK** | No errors were encountered during initialization. |
| **UPS_INITREGISTRYERROR** | An error occurred while accessing the registry. |
| **UPS_INITCOMMOPENERROR** | An error occurred while opening the COM port. |
| **UPS_INITCOMMSETUPERROR** | An error occurred while setting up the COM port. |
| **UPS_INITUNKNOWNERROR** | An unidentified error occurred. |

## Remarks

The **UPSInit** function is the first function exported by a UPS minidriver that is called by the UPS service. The function must complete all initialization operations for the minidriver, including the following:

* Opening a communication path to the UPS unit
* Determining the initial state of the UPS unit
* Updating [UPS registry entries](https://learn.microsoft.com/windows-hardware/drivers/battery/ups-registry-entries)
* Beginning the monitoring of the UPS unit

If the **UPSInit** function returns a value other than UPS_INITOK, the UPS service immediately calls the [UPSStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/upssvc/nf-upssvc-upsstop) function.

## See also

[UPSStop](https://learn.microsoft.com/windows-hardware/drivers/ddi/upssvc/nf-upssvc-upsstop)