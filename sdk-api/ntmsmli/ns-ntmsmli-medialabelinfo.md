# MediaLabelInfo structure

## Description

[[Removable Storage Manager](https://learn.microsoft.com/previous-versions/windows/desktop/bb540725(v=vs.85)) is no longer available as of Windows 7 and Windows Server 2008 R2.]

The
**MediaLabelInfo** structure conveys information to the RSM database about a tape OMID. The media label library fills in this structure for all media labels the library recognizes.

## Members

### `LabelType`

Unicode string that identifies the source of the media label. Often this is the name of the backup application or Windows command that wrote the label,
for example, "Microsoft Windows Wbadmin".

### `LabelIDSize`

Number of bytes that are used in the **LabelID** member.

### `LabelID`

Unique identifier for the media label.

### `LabelAppDescr`

Unicode string that describes the media. For example, the description for a backup media label would be similar to "Tape created on 04/14/97".

## See also

[ClaimMediaLabel](https://learn.microsoft.com/windows/desktop/api/ntmsmli/nc-ntmsmli-claimmedialabel)