# ISCSI_TARGET_PORTAL_GROUPA structure

## Description

The **ISCSI_TARGET_PORTAL_GROUP** structure contains information about the portals associated with a portal group.

## Members

### `Count`

The number of portals in the portal group.

### `Portals`

An array of [ISCSI_TARGET_PORTAL](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_target_portala) structures that describe the portals associated with the portal group. Portal names and addresses are described by either wide-character or ascii strings, depending upon implementation.

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ISCSI_TARGET_PORTAL_GROUP as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).