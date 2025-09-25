# ICustomDestinationList::AppendCategory

## Description

Defines a custom category and the destinations that it contains, for inclusion in a custom Jump List.

## Parameters

### `pszCategory` [in]

Type: **LPCWSTR**

A pointer to a string that contains the display name of the custom category. This string is shown in the category's header in the Jump List. The string can directly hold the display name or it can be an indirect string representation, such as "@shell32.dll,-1324", to use a stored string. An indirect string enables the category header to be displayed in the user's selected language.

**Note** Each custom category must have a unique name. Duplicate category names will cause presentation issues in the Jump List.

### `poa` [in]

Type: **[IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray)***

A pointer to an [IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray) that represents one or more [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) objects that represent the destinations in the category. Some destinations in the list might also be represented by [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) objects, although less often.

**Note** Any [IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) used here must declare an argument list through [SetArguments](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setarguments). Adding an **IShellLink** object with no arguments to a custom category is not supported since a user cannot pin or unpin this type of item from a Jump List, nor can they be added or removed.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise.

If the call to **AppendCategory** attempts to add an item that is in the removed destinations list retrieved by the call to [BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) that initiated the session, the call to **AppendCategory** fails.

If **AppendCategory** attempts to add an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that the application is not registered to handle, the call fails.

**AppendCategory** can fail if there is a privacy Group Policy or user privacy setting turned on. Custom categories contain user-specific items based on individual usage, which is not allowed under those privacy settings.

A privacy Group Policy or user privacy setting will not cause a failure in any other [ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist) method. Tasks are not user-specific. [AppendKnownCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendknowncategory) will not result in the display of the **Recent** or **Frequent** categories because they will have no data, but the method call will not return a failure code.

In the case of a failure code in **AppendCategory** caused by privacy Group Policy or user privacy setting (E_ACCESSDENIED), the application should continue to update tasks and call [CommitList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-commitlist).

If no file type registration was found for the associated application, **AppendCategory** returns HRESULT 0x80040F03. This can result from an application not registering the file type it is trying to add to the Jump List or from a problem in the registration, such as not providing the AppUserModelID when the application is using an explicit AppUserModelID.

## Remarks

You must call [BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) before you call this method.

If an application provides a custom category, that application assumes responsibility for populating it. The category contents should still be user-specific and based on the user's history and actions, but by using a custom category an application can determine what it wants to track and what it wants to ignore. For instance, different scenarios could be involved when different application options are chosen. For example, an audio program might elect to include only recently played albums and ignore recently played individual tracks. An application might also simply have a usage-tracking algorithm tailored to its specific use that gives better results than the system's default algorithms.

An application can call **AppendCategory** more than once in a list-building session to add multiple custom categories. In this case, the categories should be designed so that their contents are mutually exclusive. Each custom category should be built around a specific scenario so that items are not duplicated between them.

Categories in a custom Jump List, including the known **Recent** or **Frequent** categories, are shown in the order that they are added, with the most recent items added to the end of the list. If there is insufficient space to show all entries, the last entries in the list disappear off the screen first. Therefore, the most important categories should be added first to ensure their best chance of being always shown. Destinations within the category are shown in the order that they are stored in the [IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray) object pointed to by *poa*.

The user might decide to pin one or more of the destinations provided in the custom category to the Jump List. The list of pinned destinations is not available to the application, but duplication is prevented by the UI so no extra action is required of the application. Visually, a pinned item moves to the **Pinned** section of the Jump List and disappears from its original location.

A successful call to **AppendCategory** does not guarantee that those items will be displayed. Any number of destinations added over the value pointed to by the *pcMinItems* parameter in [ICustomDestinationList::BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) are not shown. The **Pinned** category takes priority over all other destination lists. The **Pinned** list is displayed, then the remaining space is allocated to the other destination lists. It is possible for a user to pin enough destinations to the Jump List to keep any other destinations from displaying. Other factors, such as a reduced screen resolution or an increased font size, can also cause application-provided destinations to be truncated from the list. The application has no way of predicting these situations and is not notified when they occur. The application must just be aware that the possibility exists. Because truncation of the destination list or lists occurs from the bottom up, the application should put its most important categories and destinations at the top of the list so that they have the best chance of being shown.

During a session started with [BeginList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-beginlist) and ending with [CommitList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-commitlist), you might call **AppendCategory** more than once. If any one of those calls fails because of an attempt to add a category that contains an item in the removed items list, the call to **CommitList** does not clear the removed items list. For the removed items list to be cleared, all calls to **AppendCategory** in a session must return successfully.

[IShellLink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllinka) instances provided through the [IObjectArray](https://learn.microsoft.com/windows/desktop/api/objectarray/nn-objectarray-iobjectarray) pointed to by *poa* must provide the following:

* Either a pointer to an item identifier list (PIDL) ([SetIDList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setidlist)) or the target path ([SetPath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setpath) or [SetRelativePath](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setrelativepath))
* Command-line arguments ([SetArguments](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setarguments))
* Icon location ([SetIconLocation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-seticonlocation))

The display name must be set through the item's [System.Title (PKEY_Title)](https://learn.microsoft.com/windows/desktop/properties/props-system-title) property. The property can directly hold the display name or it can be an indirect string representation, such as "@shell32.dll,-1324", to use a stored string. An indirect string enables the item name to be displayed in the user's selected language.

Optionally, the description field ([SetDescription](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishelllinka-setdescription)) can be set to provide a custom tooltip for the item in the Jump List.

## See also

[ICustomDestinationList](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icustomdestinationlist)

[ICustomDestinationList::AddUserTasks](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-addusertasks)

[ICustomDestinationList::AppendKnownCategory](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-icustomdestinationlist-appendknowncategory)

[Taskbar Extensions](https://learn.microsoft.com/windows/desktop/shell/taskbar-extensions)