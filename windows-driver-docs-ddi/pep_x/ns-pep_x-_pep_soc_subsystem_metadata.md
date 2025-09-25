# _PEP_SOC_SUBSYSTEM_METADATA structure (pep_x.h)

## Description

The **PEP_SOC_SUBSYSTEM_METADATA** structure contains key-value pairs that contain metadata for a system on a chip (SoC) subsystem. It is used in the context of a [PEP_DPM_QUERY_SOC_SUBSYSTEM_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_soc_subsystem_metadata) notification sent to a platform extension plug-in (PEP).

## Members

### `Key` [in/out]

 A buffer for the PEP to write the key portion of the metadata string-pair. **Key** must be unique among all **Key** values reported by this subsystem.

Prior to entry into the notification callback routine, the kernel will:

* Pre-allocate 64 **WCHARs** for **Key.Buffer[]**
* Zero the buffer
* Set **Key.MaximumLength** to the size of the buffer in bytes, and
* Set **Key.Length** = **0**

Prior to exit from the callback routine, the PEP must copy a null-terminated string into **Key.Buffer** and update **Key.Length** with a byte count that is **sizeof(WCHAR)** times the number of UNICODE characters copied, not including the terminating **UNICODE_NULL**.

The PEP must use the allocated memory that is pointed to by the address in **Key.Buffer** to provide the key.
Since this memory is pre-allocated, its size cannot be changed. The PEP is responsible for truncating the key string, if necessary, so that it does not exceed the length specified in **Key.MaximumLength** (including the terminating **UNICODE_NULL** character).

### `Value` [in/out]

A buffer for the PEP to write the value portion of the metadata string-pair.

Prior to entry into the notification callback routine, the kernel will:

* Pre-allocate 64 **WCHARs** for **Value.Buffer[]**
* Zero the buffer
* Set **Value.MaximumLength** to the size of the buffer in bytes, and
* Set **Value.Length** = **0**

Prior to exit from the callback routine, the PEP must copy a null-terminated string into **Value.Buffer** and update **Value.Length** with a byte count that is **sizeof(WCHAR)** times the number of UNICODE characters copied, not including the terminating **UNICODE_NULL**.

The PEP must use the allocated memory that is pointed to by the address in **Value.Buffer** to provide the metadata value.
Since this memory is pre-allocated, its size cannot be changed. The PEP is responsible for truncating the value string, if necessary, so that it does not exceed the length specified in **Value.MaximumLength** (including the terminating **UNICODE_NULL** character).

## See also

[PEP_DPM_QUERY_SOC_SUBSYSTEM_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_soc_subsystem_metadata)

[PEP_QUERY_SOC_SUBSYSTEM_METADATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_query_soc_subsystem_metadata)