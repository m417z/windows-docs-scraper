# PreprocessCommand function

## Description

The
**PreprocessCommand** function parses an argument string and verifies that all required tags are present.

## Parameters

### `hModule`

Reserved. Set to null.

### `ppwcArguments` [in, out]

The arguments passed to
[FN_HANDLE_CMD](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-fn_handle_cmd) (the command function) as its *ppwcArguments* parameter.

### `dwCurrentIndex` [in]

A value that specifies the first argument to process, such that *ppwcArguments*[*dwCurrentIndex*] is the first.

### `dwArgCount` [in]

The argument count passed as the *dwArgCount* parameter.

### `pttTags` [in]

An array of tags of type
**TAG_TYPE**.

### `dwTagCount` [in]

 A number of entries in the *pttTags* array.

### `dwMinArgs` [in]

The minimum number of arguments required for this command.

### `dwMaxArgs` [in]

The maximum number of arguments allowed for this command.

### `pdwTagType` [out]

An array of **DWORD**s, with at least enough space for a number of entries equal to *dwArgCount* - *dwCurrentIndex*. Each **DWORD** contains the array index number in the *pttTags* array to which the array index number in the *ppwcArguments* array is matched. For example, if *ppwcArguments*[0] is matched to *pttTags*[2], *pdwTagType*[0] is 2.

## Return value

| Return code | Description |
| --- | --- |
| **NO_ERROR** | The function completed successfully. |
| **ERROR_INVALID_SYNTAX** | Invalid syntax. |
| **ERROR_TAG_ALREADY_PRESENT** | The tag is already present. |
| **ERROR_INVALID_PARAMETER** | An invalid parameter was entered. |
| **ERROR_INVALID_OPTION_TAG** | An invalid option tag. |
| **ERROR_NOT_ENOUGH_MEMORY** | There is not enough memory available to carry out the command. |

## Remarks

The
**PreprocessCommand** function is typically called by command functions. This function parses all arguments, matching arguments with tags, and leaves the type (tag index) of each argument in the *pdwTagType* array, where *pdwTagType*[0] corresponds to the type of *ppwcArguments*[*dwCurrentIndex*]. The
**PreprocessCommand** function also ensures that tags required to be present are present.

## See also

[FN_HANDLE_CMD](https://learn.microsoft.com/previous-versions/windows/desktop/api/netsh/nc-netsh-fn_handle_cmd)

[TAG_TYPE](https://learn.microsoft.com/windows/win32/api/netsh/ns-netsh-tag_type)