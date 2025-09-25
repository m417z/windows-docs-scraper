## Description

The **EVT_ACX_FACTORY_CIRCUIT_DELETE_CIRCUITDEVICE** callback is invoked by ACX when the driver must delete a previously created WDFDEVICE associated with an ACXCIRCUIT object.

## Parameters

### `Parent`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that is the parent of the WDFDEVICE referenced in Device object.

### `Factory`

The existing circuit factory ACXFACTORYCIRCUIT Object. For more information about ACX objects, see [Summary of ACX Objects](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-summary-of-objects).

### `Device`

A WDFDEVICE object (described in [Summary of Framework Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/summary-of-framework-objects)) that must be deleted.

## Return value

Returns `STATUS_SUCCESS` if the call was successful. Otherwise, it returns an appropriate error code. For more information, see [Using NTSTATUS Values](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values).

## Remarks

An AcxFactoryCircuit represents a factory object capable of creating an ACXCIRCUIT on demand.

A driver can register one or more ACXFACTORYCIRCUIT with ACX, this action will let ACX know that the driver is capable of creating ACXCIRCUITs of a well defined type.

ACX invokes the ACXFACTORYCIRCUIT's callbacks when it detects that an audio path requires one of the factory provided ACXCIRCUITs.

This is an optional callback, if the EVT_ACX_FACTORY_CIRCUIT_DELETE_CIRCUITDEVICE callback is not defined, ACX takes the default action of removing the specified WDFDEVICE from the list of enumerated devices. This action triggers a surprise-removed PnP notification to the child WDFDEVICE.

The ACXFACTORYCIRCUIT object supports dynamic ACXCIRCUITs, this means that each ACXCIRCUIT created by the factory is associated with a WDFDEVICE and these two objects have the same lifetime.

An AcxFactoryCircuit has a dedicated WDF queue. For more information about WDF queues, see [Framework Queue Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-queue-objects).

### ACX requirements

**Minimum ACX version:** 1.0

For more information about ACX versions, see [ACX version overview](https://learn.microsoft.com/windows-hardware/drivers/audio/acx-version-overview).

## See also

- [acxcircuit.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/acxcircuit/)