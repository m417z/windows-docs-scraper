# IPhotoAcquireSettings::SetOutputFilenameTemplate

## Description

The `SetOutputFilenameTemplate` method specifies a format string (template) that specifies the format of file names.

## Parameters

### `pszTemplate` [in]

Pointer to a null-terminated string containing the format string.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

Format strings contain a mix of path literals and tokens. A format string looks like the following:

```cpp

$(MyPicturesFolder)\$(DateAcquired), $(EventName)\$(EventName) $(SequenceNumber).$(OriginalExtension)

```

The token format looks like the following, where `OptionalPrefix` and `OptionSuffix` are suppressed if the replacement for the `TokenIdentifier` yields a zero-length string:

```cpp

$([OptionalPrefix]TokenIdentifier:SubToken[OptionalSuffix]|AlternateString)

```

The caret ("^") is an escape character, so "^$" would yield "$" in the final path.

Parentheses and brackets are not allowed as literals within tokens, but can be used outside of tokens. This means you cannot use "[", "]", "(", or ")" within the `OptionalString` sub-token unless they are escaped with a caret ("^").

There are a few different classes of tokens, including the following:

**SHGetSpecialFolder** variables such as the following. These must be the first token, and can only occur once, at most:

* `MyPicturesFolder`
* `MyDocumentsFolder`

Session variables such as the following:

* `SequenceNumber` (The sequence number is used to avoid filename collisions; if it exists, it must be in the file name portion of the path.)
* `DateAcquired`
* `EventName`
* `UserName`
* `MachineName`

File and metadata variables such as the following:

* `DateTaken`
* `OriginalFilename`
* `OriginalExtension`
* `CameraModel`
* `Width`
* `Height`

Since these tokens are not intended to be visible to users, they will not be localized. For example, `$(DateTaken)` will be the same on all versions of Microsoft Windows, regardless of locale or language settings.

As an example, suppose `EventName` is "Meghan's Birthday" and the naming pattern is as follows:

``` syntax

$(MyPicturesFolder)\$(DateAcquired)$([, ]EventName)\$(EventName[ ])$(SequenceNumber).$(OriginalExtension)

```

The resulting files would be named as follows:

C:\Documents and Settings\shauniv\My Documents\My Pictures\2003-11-14, Meghan's Birthday\Meghan's Birthday 001.jpg

C:\Documents and Settings\shauniv\My Documents\My Pictures\2003-11-14, Meghan's Birthday\Meghan's Birthday 002.jpg

C:\Documents and Settings\shauniv\My Documents\My Pictures\2003-11-14, Meghan's Birthday\Meghan's Birthday 003.jpg

C:\Documents and Settings\shauniv\My Documents\My Pictures\2003-11-14, Meghan's Birthday\Meghan's Birthday 004.jpg

## See also

[GetOutputFilenameTemplate](https://learn.microsoft.com/windows/desktop/api/photoacquire/nf-photoacquire-iphotoacquiresettings-getoutputfilenametemplate)

[IPhotoAcquireSettings Interface](https://learn.microsoft.com/windows/desktop/api/photoacquire/nn-photoacquire-iphotoacquiresettings)