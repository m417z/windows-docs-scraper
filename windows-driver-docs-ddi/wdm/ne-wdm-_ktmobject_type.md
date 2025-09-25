# _KTMOBJECT_TYPE enumeration

## Description

The **KTMOBJECT_TYPE** enumeration identifies the types of objects that KTM supports.

## Constants

### `KTMOBJECT_TRANSACTION`

KTM transaction objects.

### `KTMOBJECT_TRANSACTION_MANAGER`

KTM transaction manager objects.

### `KTMOBJECT_RESOURCE_MANAGER`

KTM resource manager objects.

### `KTMOBJECT_ENLISTMENT`

KTM enlistment objects.

### `KTMOBJECT_INVALID`

Invalid object type.

## Remarks

The **KTMOBJECT_TYPE** enumeration is used with the [ZwEnumerateTransactionObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntenumeratetransactionobject) routine.

For more information about KTM objects, see [KTM Objects](https://learn.microsoft.com/windows-hardware/drivers/kernel/ktm-objects).

## See also

[ZwEnumerateTransactionObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ntenumeratetransactionobject)