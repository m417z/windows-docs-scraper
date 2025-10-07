# MPEXPIRATION\_DATA structure

Product expiration status notification.

## Members

**Reason**

Type: **MP\_EXPIRE\_REASON**

Expiration reason. This is one of the following possible values:

| Value | Meaning |
|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------|
|

**MP\_EXPIRED\_UNKNOWN**

0

| Unknown.<br> |
|

**MP\_EXPIRED\_EVAL**

1

| Evaluation.<br> |
|

**MP\_EXPIRED\_WAT**

2

| WAT.<br> |

**State**

Type: **MP\_EXPIRE\_STATE\_REPORT**

Expiration state. This is one of the following possible values:

| Value | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------|
|

**MP\_EXPIRE\_STATE\_REPORT\_UNKNOWN**

0

| State unknown.<br> |
|

**MP\_EXPIRE\_STATE\_REPORT\_VALID**

1

| No expiration.<br> |
|

**MP\_EXPIRE\_STATE\_REPORT\_WARNING**

2

| Near expired.<br> |
|

**MP\_EXPIRE\_STATE\_REPORT\_EXPIRED**

3

| Expired.<br> |

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

