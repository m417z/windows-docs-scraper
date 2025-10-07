# WMDMMetadataView structure

The **WMDMMetadataView** structure defines the metadata view. Content is organized based on this definition.

## Members

**pwszViewName**

Pointer to a wide-character null-terminated string containing the name of the view. This is used as the name of the root node under which this view is presented.

**nDepth**

Integer containing the depth of the view, which indicates how many nested metadata tags are used for the view.

**ppwszTags**

Array of metadata tag strings for the nested tags.

## Examples

The following code creates a metadata view:

```C++
WMDMMetadataView view;
view.pwszName = L"My View";
view.nDepth = 3;  // genre, artist, album
LPCWSTR wszTagArray[3];
wszTagArray[0] = g_wszWMDMGenre;
wszTagArray[1] = g_wszWMDMAuthor;
wszTagArray[2] = g_wszWMDMAlbumTitle;
view.ppwszTags = wszTagArray;
```

The preceding code organizes content as follows:

My View

Genre1

Artist1

Album1

Song1
Song2
...

 Album2
...

 Artist2

Album1

Song1
Song2
...

 Album2
...

 Genre2

Artist1

Album1

Song1
Song2
...

 Album2
...

 Artist2

Album1

Song1
Song2
...

 Album2
...

 ...

 ...

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | Wmdm.idl |

## See also

[**Structures**](https://learn.microsoft.com/windows/win32/wmdm/structures)

