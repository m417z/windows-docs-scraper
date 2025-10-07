# TABLET\_CONTEXT\_SETTINGS structure

Contains information used in creating a tablet context.

## Members

**cPktProps**

The number of properties in a packet.

**pguidPktProps**

Unique identifiers for the packet properties.

**cPktBtns**

The number of buttons.

**pguidPktBtns**

Unique identifiers for the buttons.

**pdwBtnDnMask**

The button down mask.

**pdwBtnUpMask**

The button up mask.

**lXMargin**

The X direction margin.

**lYMargin**

The Y direction margin.

## Remarks

Typically, an application obtains the default values from the [**ITablet::GetDefaultContextSettings Method**](https://learn.microsoft.com/windows/win32/tablet/itablet-getdefaultcontextsettings), modifies values to suit their needs, and then passes the modified settings structure to the [**ITablet::CreateContext Method**](https://learn.microsoft.com/windows/win32/tablet/itablet-createcontext).

This structure determines what events an application will get, how they will be processed, and how they will be delivered to the application or to Windows itself.

The button masks together determine what kinds of events will be processed by the context.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------|
| Minimum supported client<br> | Windows XP Tablet PC Edition \[desktop apps only\]<br> |
| Minimum supported server<br> | None supported<br> |

