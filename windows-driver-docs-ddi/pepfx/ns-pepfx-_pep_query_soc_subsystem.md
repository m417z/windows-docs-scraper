# _PEP_QUERY_SOC_SUBSYSTEM structure (pepfx.h)

## Description

The **PEP_QUERY_SOC_SUBSYSTEM** structure is used by the [PEP_DPM_QUERY_SOC_SUBSYSTEM notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/) to gather basic information about a particular system on a chip (SoC) subsystem.

## Members

### `PlatformIdleStateIndex` [in]

The platform idle state index that is being queried by the kernel.

### `SubsystemIndex` [in]

The subsystem index, which is a unique index assigned by the OS to each subsystem within the context of a given **PlatformIdleStateIndex**.

The kernel initializes this value to zero and increments it for each subsequent subsystem static info notification. A value of 0 means it's the first such notification for the given **PlatformIdleStateIndex**. This field is intended to give the PEP context between instances of this notification. It is the only field whose input value varies across instances of this notification for a given **PlatformIdleStateIndex** and a PEP might use this value to look up a subsystem.

The PEP can ignore this value.

### `SubsystemHandle` [out]

A context pointer that the PEP can optionally assign a value to. It will receive the pointer on subsequent notifications for this particular subsystem. In subsequent notifications, a PEP uses **PlatformIdleStateIndex** along with **SubsystemName** and/or **SubsystemHandle** to look up a particular subsystem's accounting data.

By default the value if this member is zero. This value is ignored by the OS and used only in notifications.

The PEP is not required to fill this member.

### `ParentName` [in/out]

 A buffer for holding the parent name of the corresponding subsystem. Each subsystem has a parent and subsystems with the same value for **ParentName** are considered siblings. Subsystem sibling hierarchies are optional. In the absence of any hierarchy, all subsystems are top level subsystems and specify a common value for **ParentName**. To indicate a hierarchy, top level subsystems specify a common **ParentName** while each non-top-level subsystem specifies its parent subsystem's **SubsystemName** for **ParentName**.

Prior to entry, the kernel will:

* Pre-allocate 64 **WCHARs** for **ParentName.Buffer[]**
* Zero the buffer
* Set **ParentName.MaximumLength** to the size of the buffer in bytes, and
* Set **ParentName.Length** = **0**

Prior to exit, the PEP must copy a null-terminated string into **ParentName.Buffer** and update **ParentName.Length** with a byte count that is **sizeof(WCHAR)** times the number of UNICODE characters copied, not including the terminating **UNICODE_NULL**.

The PEP must use the allocated memory that is pointed to by the address in **ParentName.Buffer** to provide the parent name.
Since this memory is pre-allocated, its size cannot be changed. The PEP is responsible for truncating the parent name, if necessary, so that it does not exceed the length specified in **ParentName.MaximumLength** (including the terminating **UNICODE_NULL** character).

### `SubsystemName` [in/out]

A buffer for holding this subsystem's name. Every subsystem has a subsystem name and **SubsystemName** must be unique among all subsystems within the context of a given platform idle state. A subsystem's **SubsystemName** cannot be the same as **ParentName**.

Prior to entry, the kernel will:

* Pre-allocate 64 **WCHARs** for **SubsystemName.Buffer[]**
* Zero the buffer
* Set **SubsystemName.MaximumLength** to the size of the buffer in bytes, and
* Set **SubsystemName.Length** = **0**

Prior to exit, the PEP must copy a null-terminated string into **SubsystemName.Buffer** and update **SubsystemName.Length** with a byte count that is **sizeof(WCHAR)** times the number of UNICODE characters copied, not including the terminating **UNICODE_NULL**.

The PEP must use the allocated memory that is pointed to by the address in **SubsystemName.Buffer** to provide the subsystem name.
Since this memory is pre-allocated, its size cannot be changed. The PEP is responsible for truncating the subsystem name, if necessary, so that it does not exceed the length specified in **SubsystemName.MaximumLength** (including the terminating **UNICODE_NULL** character).

### `MetadataCount` [out]

The number of metadata key/value string pairs tallied by this SoC subsystem.

Metadata is optional. The PEP returns zero if it does not report any metadata for this SoC subsystem.

### `Flags`

This member is reserved and should be set to zero.

## See also

[PEP_DPM_QUERY_SOC_SUBSYSTEM notification](https://learn.microsoft.com/windows-hardware/drivers/ddi/)