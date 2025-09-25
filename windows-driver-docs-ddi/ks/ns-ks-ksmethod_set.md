# KSMETHOD_SET structure

## Description

The KSMETHOD_SET structure describes the methods that comprise a kernel streaming method set.

## Members

### `Set`

Specifies a GUID the identifies the kernel streaming method set. For more information about method set GUIDs, see **Remarks**.

### `MethodsCount`

Specifies the number of methods in this method set.

### `MethodItem`

Points to an array of [KSMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item) structures. Each structure describes one method of the method set.

### `FastIoCount`

Reserved for system use. Do not use.

### `FastIoTable`

Reserved for system use. Do not use.

## Remarks

Microsoft provides several system-defined kernel streaming method set GUIDs. Minidrivers specify one of these GUIDs in the **Set** member. Kernel streaming method sets typically begin with a *KSMETHODSETID* prefix. Method set GUIDs are defined in *ks.h*, *ksmedia.h*, *bdamedia.h*, and possibly other header files.

## See also

[KSMETHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksmethod_item)