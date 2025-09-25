# ISCSI_SESSION_INFOW structure

## Description

The **ISCSI_SESSION_INFO** structure contains session information.

## Members

### `SessionId`

A [ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id) structure containing a unique identifier that represents the session.

### `InitiatorName`

A string that represents the initiator name.

### `TargetNodeName`

A string that represents the target node name.

### `TargetName`

A string that represents the target name.

### `ISID`

The initiator-side identifier (ISID) used in the iSCSI protocol.

### `TSID`

The target-side identifier (TSID) used in the iSCSI protocol.

### `ConnectionCount`

The number of connections associated with the session.

### `Connections`

A pointer to a [ISCSI_CONNECTION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_connection_infoa) structure.

## See also

[GetIScsiSessionList](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/nf-iscsidsc-getiscsisessionlista)

[ISCSI_CONNECTION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_connection_infoa)

[ISCSI_UNIQUE_SESSION_ID](https://learn.microsoft.com/windows/desktop/api/iscsidsc/ns-iscsidsc-iscsi_unique_session_id)

## Remarks

> [!NOTE]
> The iscsidsc.h header defines ISCSI_SESSION_INFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).