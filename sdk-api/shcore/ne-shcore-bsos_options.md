# BSOS_OPTIONS enumeration

## Description

Specifies the behavior of a [RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream) that encapsulates a Component Object Model (COM) [IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream).

## Constants

### `BSOS_DEFAULT:0`

When creating a [RandomAccessStream](https://learn.microsoft.com/uwp/api/windows.storage.streams.randomaccessstream) over a stream, use the base [IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85)) behavior on the [STGM](https://learn.microsoft.com/windows/desktop/api/wtypes/ne-wtypes-stgmove) mode from the [Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istream-stat) method.

### `BSOS_PREFERDESTINATIONSTREAM`

Use the [GetDestinationStream](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idestinationstreamfactory-getdestinationstream) method.

## See also

[IRandomAccessStream](https://learn.microsoft.com/previous-versions/hh438400(v=vs.85))

[IStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-istream)