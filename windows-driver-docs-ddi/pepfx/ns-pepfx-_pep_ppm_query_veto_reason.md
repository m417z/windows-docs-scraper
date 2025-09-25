# _PEP_PPM_QUERY_VETO_REASON structure (pepfx.h)

## Description

The **PEP_PPM_QUERY_VETO_REASON** structure supplies a wide-character, null-terminated string that contains a descriptive, human-readable name for a veto reason.

## Members

### `VetoReason` [in]

The index that identifies this veto reason. If the platform extension plug-in (PEP) supports N veto reasons, valid veto reason indexes range from 1 to N. The PEP previously specified the number of supported veto reasons in response to a [PEP_NOTIFY_PPM_QUERY_VETO_REASONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason) notification.

### `NameSize` [out]

The size, in bytes, of the string buffer pointed to by the **Name** member. This string size includes the storage space for the null character that terminates the wide-character string.

### `Name` [in]

A pointer to a PoFx-allocated string buffer. If this buffer pointer is non-**NULL**, the PEP writes a wide-character, null-terminated string to the buffer (and writes nothing to the **NameSize** member). Otherwise, the PEP writes nothing to this buffer and instead writes the required string size to the **NameSize** member.

## Remarks

This structure is used by the [PEP_NOTIFY_PPM_QUERY_VETO_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason) notification. The **VetoReason** and **Name** members contain input values that are supplied by the Windows [power management framework](https://learn.microsoft.com/windows-hardware/drivers/ddi/_kernel/#device-power-management) (PoFx). If the input value of the **Name** member is **NULL**, the PEP writes an output value (the required string buffer size) to the **NameSize** member.

## See also

[PEP_NOTIFY_PPM_QUERY_VETO_REASON](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason)

[PEP_NOTIFY_PPM_QUERY_VETO_REASONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/pepfx/ns-pepfx-_pep_ppm_query_veto_reason)