# TAPE_PREPARE structure

## Description

The
**TAPE_PREPARE** structure describes how to prepare the tape.

## Members

### `Operation`

Tape preparation option. This member must be one of the following values.

| Value | Meaning |
| --- | --- |
| **TAPE_LOCK**<br><br>3L | Locks the tape ejection mechanism so that the tape is not ejected accidentally during a tape operation. |
| **TAPE_TENSION**<br><br>2L | Moves to the end of the tape and rewinds to the beginning of the tape. This value is ignored if the tape device does not support tensioning. |
| **TAPE_UNLOAD**<br><br>1L | Rewinds and unloads the tape. |
| **TAPE_UNLOCK**<br><br>4L | Unlocks the tape ejection mechanism. |

### `Immediate`