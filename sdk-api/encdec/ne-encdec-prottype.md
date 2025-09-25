# ProtType enumeration

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Windows XP Service Pack 1 or later.

The **ProtType** enumeration type specifies various types of content protection.

## Constants

### `PROT_COPY_FREE:1`

Copy Free.

### `PROT_COPY_ONCE:2`

Copy Once.

### `PROT_COPY_NEVER:3`

Copy Never.

### `PROT_COPY_NEVER_REALLY:4`

Reserved.

### `PROT_COPY_NO_MORE:5`

Copy No More.

### `PROT_COPY_FREE_CIT:6`

The Copy Control Information (CCI) flag indicates Copy Free, but the Constrained Image Trigger (CIT) bit is set. The content is encrypted.

### `PROT_COPY_BF:7`

Reserved.

### `PROT_COPY_CN_RECORDING_STOP:8`

Reserved.

### `PROT_COPY_FREE_SECURE:9`

The Copy Control Information (CCI) flag indicates Copy Free, but the Redistribution Control Trigger (RCT) bit is set. The content is encrypted.

### `PROT_COPY_INVALID:50`

Error or invalid protection scheme. Treat as Copy Never.

## See also

[EnTvRat_GenericLevel](https://learn.microsoft.com/previous-versions/dd375610(v=vs.85))

[TV Ratings Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/tv-ratings-enumerations)