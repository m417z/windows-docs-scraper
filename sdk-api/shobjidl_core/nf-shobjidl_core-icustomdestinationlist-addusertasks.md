# ICustomDestinationList::AddUserTasks

## Description

Specifies items to include in the **Tasks** category of a custom Jump List.

## Parameters

### `poa` [in]

Type: **[IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray)***

A pointer to an [IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray) that represents one or more [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) (or, more rarely, [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)) objects that represent the tasks.

**Note** Any [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) used here must declare an argument list through [SetArguments](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setarguments). Adding an **IShellLink** object with no arguments to a custom category is not supported. A user cannot pin or unpin this type of item from a Jump List, nor can they be added or removed.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

## Remarks

You must call [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) before you call this method.

The **Tasks** category header is always shown in the list by default, unless the category is empty. This header text cannot be changed. It is displayed in the user's selected language.

The **Tasks** category, even though it always appears as the last category in a Jump List, takes priority over all other categories in the list. This list is filled, and then the remaining space is allocated to the other categories. Unlike other categories, items in the **Tasks** category cannot be removed or pinned by the user. Applications must balance the value to the user of the tasks in this category against the space needed for other categories.

Tasks should apply to the application as a whole; they are not meant to be specific to an individual window or document. For those more granular contextual tasks, an application can supply them through a [thumbnail toolbar](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-itaskbarlist3-thumbbaraddbuttons).

**Note** It is strongly recommended that the task list be static. The task list should remain the same regardless of the state or status of the application—these tasks are available even when the application is not running. There is no programmatic prohibition against using **AddUserTasks** to vary the task list when it is updated, but you should consider that this could confuse the user who does not expect that portion of the Jump List to change. However, if an application does opt to change the state of a task, such as "Sign In" to "Sign Out", it is the responsibility of that application to ensure that the task list is correct and up to date. Also, if the application unexpectedly shuts down, the taskbar will use its last known good version of the task list without calling into the application to request one, leading to the possibility of out of date items.

[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) instances provided through the [IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray) pointed to by *poa* must provide the following:

* Either a pointer to an item identifier list (PIDL) ([SetIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setidlist)) or the target path ([SetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setpath) or [SetRelativePath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setrelativepath))
* Command-line arguments ([SetArguments](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setarguments))
* Icon location ([SetIconLocation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-seticonlocation))

The display name must be set through the item's [System.Title (PKEY_Title)](https://learn.microsoft.com/windows/desktop/properties/props-system-title) property. The property can directly hold the display name or it can be an indirect string representation, such as "@shell32.dll,-1324", to use a stored string. An indirect string enables the item name to be displayed in the user's selected language.

Optionally, the description field ([SetDescription](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setdescription)) can be set to provide a custom tooltip for the item in the Jump List.

A task list can also include separators. These are created by including a blank [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) (this is the single exception to the argument list requirement), and setting its [System.AppUserModel.IsDestListSeparator](https://learn.microsoft.com/windows/desktop/properties/props-system-appusermodel-isdestlistseparator) property to **TRUE** through the **IShellLink** object's [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface. Any other values in the **IShellLink** will be ignored. Separators do not take up a full space in the list and are not counted in the number of items in the list. If two separators are provided with no items between them, one of the separators will not be shown. Separators at the beginning or end of the list are also ignored.

## See also

[ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist)

[ICustomDestinationList::AppendCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendcategory)

[ICustomDestinationList::AppendKnownCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendknowncategory)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)