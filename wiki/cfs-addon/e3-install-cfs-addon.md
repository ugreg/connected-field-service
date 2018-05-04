## Exercise 3: Install Connected Field Service ( CFS ) Add-on

1. On your computer, browse to AppSource here [https://appsource.microsoft.com/en-us/product/dynamics-365/mscrm.58666c7d-65ee-452d-8708-70b4d471d4c0](https://appsource.microsoft.com/en-us/product/dynamics-365/mscrm.58666c7d-65ee-452d-8708-70b4d471d4c0) and download the ["Connected Field Service Add-On"](https://appsource.microsoft.com/en-us/product/dynamics-365/mscrm.58666c7d-65ee-452d-8708-70b4d471d4c0) by clicking `GET IN NOW`.

  gregdegury@gregdegruy.onmicrosoft.com and https://gregdegruy.crm.dynamics.com/main.aspx

  <img src="imgs/appsource-cfs-addon.png">

2. You should now see a prompt notifying you that you are being taken to Dynamics 365 to complete the process.

  <img src="imgs/appsource-cfs-addon-permissions.png">

3. The first step in configuring your Connected Field Service environment is choosing the Dynamics 365 organization you want to install the Connected Field Service Add-On too.
  - `A` Your Dynamics 365 organization is auto selected for you
  - `B` Check off the two boxes to agree to the terms of use
  - `C` Click the `Agree` button

  <img src="imgs/dyn-appsource-install-select-org.png">

4. Read over the Terms of service. Click `Next` when you're ready.

  <img src="imgs/dyn-appsource-terms-of-service.png">

5. Read over the Privacy statement. Click `Next` when you're ready.

  <img src="imgs/dyn-appsource-install-privacy-statement.png">

6. Verify the Dynamics 365 subscription where the Internet of Things solution will be deployed is selected properly.
  - `A` Your Dynamics 365 organization is auto selected for you
  - `B` Click the `Next` button

  <img src="imgs/dyn-appsource-install-select-org-iot-solution.png">

7.	Let's setup the Azure IoT connector services for your Dynamics organization.
  - `A` Your Azure Trial is auto selected for you and should say "Free Trial", this came from the work we did in Exercise 2.
  - `B` Choose `Create new` for our Resources
  - `C` Check Enable Power BI Integration. In my case I choose "gregdegruy" as my SQL Server Admin Login and... not about to give you my password silly :P.

  > NOTE
  >
  > Make sure you fill in **SQL Server Admin Login**, **SQL Password**, and **Confirm Password**

  - `D` Choose `Create new` for our Resource Group Selection
  - `E` Give your Resource Group a name and deployment region, in my case I called it "rg-connected-field-service" and choose "West US".

  > NOTE
  >
  > Make sure you choose both a **Resource Group Name** and **Deployment Region**

  - `F` Click the `Deploy` button

  <img src="imgs/dyn-appsource-install-az-services.png">

8. Your Azure IoT connector services for your Dynamics organization are not automatically deploying for you! Starting with your Azure StorageAccount that currently has a InProgress Deployment Status, but will soon be at this Success and so will the other services that will slowly appear under Resource Type. This is going to take a while :/ around 25 minutes to be exact.

  <img src="imgs/dyn-appsource-install-az-services-inprog.png">

9.	Once deployment is completed, you'll notice all services will have a Success Deployment Status. You should now be able to click the Authorize button that will take you to your Azure Portal where we will complete our setup. Click the `Authorize` button.

  <img src="imgs/dyn-appsource-install-az-services-complete.png">

10.	The first windows you'll see in your Azure portal is for the dynamicscrmonline API Connection service. We need to authorize this API Connection service to connect to our Dynamics organization.
  - `A` Click "This connection is not authenticated" highlighted in yellow.

  <img src="imgs/az-crm-online-api-connector.png">  

  - `B` Give your connection a name and click `Authorize`

  <img src="imgs/az-crm-online-api-connector-name.png">  

  - `C` A Window will open for you to pick your Microsoft account login. We created this login in Exercise 1 step 6, only one login should be shown show so select it.

  <img src="imgs/az-crm-online-api-connector-auth.png">  

  - `D` The window will close and you'll now have the option to save your API connection information, click `Save`.

  <img src="imgs/az-crm-online-api-connector-complete.png">  

11.	Now that we have an authorized API connection between Azure and Dynamics, we can start configuring our IoT Hub. This IoT Hub serves as our management service for the IoT device. Click on `Resource Groups` from the left menu.

  <img src="imgs/az-menu-rg-from-apiconn.png">  

12.	This will bring you to the resource group selection list. We created this resource group in Exercise 3 step 7 and contains all of the IoT connector service we'll be using. Click on `rg-connected-field-service`.

  <img src="imgs/az-rg-list.png">  

13.	Click on your IoT Hub. It is named the same as your Resource Group with a long list of letters and numbers in the form of a GUID, in my case it's called `rgconnectedfieldservice8e3aca9cda474acd82c08f5a`.

  <img src="imgs/az-rg-iothub.png">  

14.	Now we need to add a Shared access policy to create a connection between our IoT Hub and Dynamics.
  - `A` Click "Shared access policy" from the IoT Hub menu.
  - `B` Click "+ Add" at the very top of the Shares access policy list.

  <img src="imgs/az-iothub-sas-a.png">  
  <img src="imgs/az-iothub-sas-b.png">  

15.	Then give the Shared access policy the permissions it needs to communicate with Dynamics.
  - `A` Give your policy a name, I called mine "dynamics-iot-hub"
  - `B` Select the `Registry read`, `Registry write`, and `Device connect` permissions
  - `C` Click the `Create` button

  > NOTE
  >
  > Make sure you select all 3 permissions **Registry read**, **Registry write**, and **Device connect** before creating the policy.

  <img src="imgs/az-iothub-sas-permissions.png">  

16.	Once created, the shared access policy will provide 4 keys to you. The one we will need going forward is the `Primary Key`, click the copy button for the primary key and save it in Notepad. Notepad can be open by clicking the `A` Cortana button next to the Windows icon and typing in Notepad. It will be the first app on the list that you can then `B` click on.

  <img src="imgs/az-iothub-sas-key.png">  
  <img src="imgs/win-open-notepad.png">

17.	Now that we have SAS key saved, we can head to our device simulator. This simulator is a web app that we can use to see real time IoT device telemetry. Click on `Resource Groups` from the left menu.

  <img src="imgs/az-menu-rg-from-sas.png">  

18.	This will bring you to the resource group selection list. We created this resource group in Exercise 3 step 7 and contains all of the App service we'll be using for our simulator. Click on `rg-connected-field-service`.

  <img src="imgs/az-rg-list.png">  

19.	Click on your Simulator App Service. It is named Simulator followed by the same name as your Resource Group with a long list of letters and numbers in the form of a GUID, in my case it's called `Simulatorrgconnectedfieldservice8b0afe2802a54b3`.

  <img src="imgs/az-rg-simulator-appservice.png">  

20. After you click on your Simulator App Service, you'll be brought to the main page for your App Service. Move your mouse to the right of the URL link, a copy button will appear. Click the copy button to copy the URL. In a new browser tab, paste the URL.

  <img src="imgs/az-rg-simulator-appservice-url.png">

21. You should now be on your IoT device simulator website.

  <img src="imgs/simulator-appservice-website.png">  
