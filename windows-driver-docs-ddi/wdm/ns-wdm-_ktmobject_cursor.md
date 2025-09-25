# _KTMOBJECT_CURSOR structure

## Description

The **KTMOBJECT_CURSOR** structure receives enumeration information about KTM objects when a component calls [ZwEnumerateTransactionObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntenumeratetransactionobject).

## Members

### `LastQuery`

After **ZwEnumerateTransactionObject** returns, this member contains the GUID of the last object that **ZwEnumerateTransactionObject** enumerated. Before it calls **ZwEnumerateTransactionObject** the first time, the caller must set this value to zero.

### `ObjectIdCount`

After **ZwEnumerateTransactionObject** returns, this member contains the number of GUIDs that the **ObjectIds** array contains.

### `ObjectIds`

A caller-allocated array of GUID-typed elements. After **ZwEnumerateTransactionObject** returns, this array contains GUIDs that identify enumerated objects.

## Remarks

The **KTMOBJECT_CURSOR** structure is used at the beginning of buffers that callers pass to the **ZwEnumerateTransactionObject** routine.

## See also

[ZwEnumerateTransactionObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntenumeratetransactionobject)