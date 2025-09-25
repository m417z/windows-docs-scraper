# AVIStreamFindSample function

## Description

The **AVIStreamFindSample** function returns the position of a sample (key frame, nonempty frame, or a frame containing a format change) relative to the specified position.

This function supersedes the obsolete **AVIStreamFindKeyFrame** function.

## Parameters

### `pavi`

Handle to an open stream.

### `lPos`

Starting frame for the search.

### `lFlags`

Flags that designate the type of frame to locate, the direction in the stream to search, and the type of return information. The following flags are defined.

| Value | Meaning |
| --- | --- |
| FIND_ANY | Finds a nonempty frame. This flag supersedes the SEARCH_ANY flag. |
| FIND_KEY | Finds a key frame. This flag supersedes the SEARCH_KEY flag. |
| FIND_FORMAT | Finds a format change. |
| FIND_NEXT | Finds nearest sample, frame, or format change searching forward. The current sample is included in the search. Use this flag with the FIND_ANY, FIND_KEY, or FIND_FORMAT flag. This flag supersedes the SEARCH_FORWARD flag. |
| FIND_PREV | Finds nearest sample, frame, or format change searching backward. The current sample is included in the search. Use this flag with the FIND_ANY, FIND_KEY, or FIND_FORMAT flag. This flag supersedes the SEARCH_NEAREST and SEARCH_BACKWARD flags. |
| FIND_FROM_START | Finds first sample, frame, or format change beginning from the start of the stream. Use this flag with the FIND_ANY, FIND_KEY, or FIND_FORMAT flag. |

## Return value

Returns the position of the frame found or -1 if the search is unsuccessful.

## Remarks

The FIND_KEY, FIND_ANY, and FIND_FORMAT flags are mutually exclusive, as are the FIND_NEXT and FIND_PREV flags.

The argument *pavi* contains a pointer to an [IAVIStream](https://learn.microsoft.com/windows/desktop/api/vfw/nn-vfw-iavistream) interface.

## See also

[AVIFile Functions](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions)

[AVIFile Functions and Macros](https://learn.microsoft.com/windows/desktop/Multimedia/avifile-functions-and-macros)