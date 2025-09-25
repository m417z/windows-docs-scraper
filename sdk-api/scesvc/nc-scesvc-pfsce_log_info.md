# PFSCE_LOG_INFO callback function

## Description

The *PFSCE_LOG_INFO* callback function logs messages to the configuration log file or analysis log file.

## Parameters

### `ErrLevel` [in]

Specifies the level of information to log. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **SCE_LOG_LEVEL_ALWAYS** | Records all actions in the log file. |
| **SCE_LOG_LEVEL_ERROR** | Records errors in the log file. |
| **SCE_LOG_LEVEL_DETAIL** | Records detailed information in the log file. |
| **SCE_LOG_LEVEL_DEBUG** | Records debug information in the log file. |

### `Win32rc` [in]

Specifies the Windows result code to log.

### `pErrFmt` [in]

Specifies the result format. This parameter uses the same format conventions as the C library function **printf**.

### `unnamedParam1`

####### - ... [in]

Variable-length list of arguments specified by *pErrFmt*. For example, if the string pointed to by *pErrFmt* is "%d%s%d", *pErrFmt* is followed by three additional arguments: a **DWORD**, a string, and another **DWORD**.

## Return value

If the function succeeds, it returns SCESTATUS_SUCCESS; otherwise, an error code is returned.