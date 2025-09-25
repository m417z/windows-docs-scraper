# WPCFLAG_ISBLOCKED enumeration

## Description

Indicates information about what events are blocked from use and what controls are in place.

## Constants

### `WPCFLAG_ISBLOCKED_NOTBLOCKED:0x00000000`

No events are blocked from the user.

### `WPCFLAG_ISBLOCKED_IMBLOCKED:0x00000001`

Instant messaging is blocked from the user.

### `WPCFLAG_ISBLOCKED_EMAILBLOCKED:0x00000002`

Email access is blocked from the user.

### `WPCFLAG_ISBLOCKED_MEDIAPLAYBACKBLOCKED:0x00000004`

Playing of media files is blocked from the user.

### `WPCFLAG_ISBLOCKED_WEBBLOCKED:0x00000008`

Internet access is blocked from the user.

### `WPCFLAG_ISBLOCKED_GAMESBLOCKED:0x00000010`

Games are blocked from the user.

### `WPCFLAG_ISBLOCKED_CONTACTBLOCKED:0x00000020`

The contacts list is blocked from the user.

### `WPCFLAG_ISBLOCKED_FEATUREBLOCKED:0x00000040`

Features are blocked from the user.

### `WPCFLAG_ISBLOCKED_DOWNLOADBLOCKED:0x00000080`

The ability to download files is blocked from the user.

### `WPCFLAG_ISBLOCKED_RATINGBLOCKED:0x00000100`

Content with a specified rating is blocked from the user.

### `WPCFLAG_ISBLOCKED_DESCRIPTORBLOCKED:0x00000200`

The description of the content is blocked from the user.

### `WPCFLAG_ISBLOCKED_EXPLICITBLOCK:0x00000400`

Explicit content is blocked from the user.

### `WPCFLAG_ISBLOCKED_BADPASS:0x00000800`

The user has entered a password that is not valid.

### `WPCFLAG_ISBLOCKED_MAXHOURS:0x00001000`

The user has reached the maximum number of hours allowed for computer access.

### `WPCFLAG_ISBLOCKED_SPECHOURS:0x00002000`

The user is blocked from computer access because the time is outside of the specified hours allowed for this user.

### `WPCFLAG_ISBLOCKED_SETTINGSCHANGEBLOCKED:0x00004000`

The user is blocked from changing any computer settings.

### `WPCFLAG_ISBLOCKED_ATTACHMENTBLOCKED:0x00008000`

An attachment is blocked from the user.

### `WPCFLAG_ISBLOCKED_SENDERBLOCKED:0x00010000`

The user is blocked from sending any information to the specified account.

### `WPCFLAG_ISBLOCKED_RECEIVERBLOCKED:0x00020000`

The user is blocked from receiving any information from the specified account.

### `WPCFLAG_ISBLOCKED_NOTEXPLICITLYALLOWED:0x00040000`

The user is blocked because the feature is not explicitly allowed.

### `WPCFLAG_ISBLOCKED_NOTINLIST:0x00080000`

The user is blocked because the feature is not listed as accessible.

### `WPCFLAG_ISBLOCKED_CATEGORYBLOCKED:0x00100000`

The user is blocked from accessing the entire category of activity.

### `WPCFLAG_ISBLOCKED_CATEGORYNOTINLIST:0x00200000`

The user is blocked because the category is not listed as accessible.

### `WPCFLAG_ISBLOCKED_NOTKIDS:0x00400000`

The user is blocked because the rating specifies that the content is not suitable for children.

### `WPCFLAG_ISBLOCKED_UNRATED:0x00800000`

The user is blocked because the content is not rated.

### `WPCFLAG_ISBLOCKED_NOACCESS:0x01000000`

The user is blocked from any access.

### `WPCFLAG_ISBLOCKED_INTERNALERROR:0xFFFFFFFF`

The user is blocked by an internal error.