
<img src="imgs/md/dyn-logo.png">

# Intro to Dynamics 365 Connected Field Service
---
The goal of this repo is to give you everything you need to set up a Connected Field Service (CFS) Environment. using both the first timer recommended [CFS](https://appsource.microsoft.com/en-us/product/dynamics-365/mscrm.58666c7d-65ee-452d-8708-70b4d471d4c0) and more advanced custom Azure deployment.

# Goals
| <p align="center"><img src="imgs/md/code-file.svg" width="64"></p> [1. Provision Dynamics 365](Assets/HoloToolkit/Input/README.md) | <p align="center"><img src="imgs/md/resources.svg" width="64"></p> [2. Provision Azure Trail](Assets/HoloToolkit/Sharing/README.md) | <p align="center"><img src="imgs/md/generics.svg" width="64"></p> [3. Setup MX Chip](Assets/HoloToolkit/SpatialMapping/README.md) |
| :- | :- | :- |
| `{ blurb here }` | `{ blurb here }` | `{ blurb here }` |
| <p align="center"><img src="imgs/md/generics.svg" width="64"></p> [4. Setup MX Chip](Assets/HoloToolkit/SpatialMapping/README.md) | <p align="center"><img src="imgs/md/linq.svg" width="64"></p> [5. Configure Connect Field Service Add-On](Assets/HoloToolkit/SpatialUnderstanding/README.md) | <p align="center"><img src="imgs/md/exception.svg" width="64"></p> [6. Write Your First App](Assets/HoloToolkit/SpatialUnderstanding/README.md) |
| `{ blurb here }` | `{ blurb here }` | `{ blurb here }` |

## Finished Product
`{ .gif goes here }`


## Step 1: Provision Dynamics 365

1.	From a Web Browser on your computer, visit the [Dynamics 365 for Field Service home page](https://www.microsoft.com/en-us/dynamics365/field-service) and click the `START FREE >` button.

  <img src="imgs/provision-dynfs-homepage.png">

2. Start your digital transformation!
  - `A` Select the Field Service app if it is not selected already
  - `B` Click `Sign up here`

    <img src="imgs/provision-dynfs-fsapp-form.png">

    > IMPORTANT
    >
    > Do not fill out work email and phone number and Do not click `GET STARTED >`

3. Next you'll be naviagted to provision your new Dynamics Trail. Fill out the general information about yourself and your company then click `Next`.

  <img src="imgs/provision-dynfs-personal-info.png">

4. Enter your user ID information and click `Create my account`.

  <img src="imgs/provision-dynfs-user-id.png">

5. Lastly you'll have to confirm your identity using your phone, enter your phone number and click `Text me ->`.

  <img src="imgs/provision-dynfs-phone.png">

6. After phone authentication is complete, you'll be given some important URLS that you should note down while the signup is finishing. Once the signup is finished click the `Set up` that appears.

  <img src="imgs/provision-dynfs-completed.png">

  > NOTE
  >
  > Keep the "Sign-in page" and "user ID" copied somewhere on your computer like a text file, you will need this information later.

7.	Now you should be on the Dynamics 365 FREE 30 Trial set up page.
  - `A` Field service should already be checked, if not make sure to click the check box.
  - `B` Click `Complete Setup`, A "Setting Up..." alert will appear.
  - `C` After the setup is complete you'll get another alert letting you know your Trial Organization will be ready soon!

    <img src="imgs/dyn-free-trial-intro.png">

    <img src="imgs/provision-dynfs-trail-email-alert.png">

8. Head over the [Outlook mail website](https://outlook.office.com/owa/) and sign in with your business email address from step 3. Find the email from Microsoft Dynamics CRM Online and click the `Get Started` button from that email.

  <img src="imgs/dyn-confirmation-email.png">

9. Welcome to Dynamics 365! No let's make sure your account has the right permissions going forward to complete the rest of the exercises we have in store.

  <img src="imgs/dyn-fs.png">

9.	We're going to do this by navigating through our organization's Site Map.
  - `A` Click the drop down arrow next to `Field service`
  - `B` Then click `Settings` to open our system and application settings
  - `C` Click `Security` under System settings

  <img src="imgs/dyn-sitemap-fs.png">

  <img src="imgs/dyn-sitemap-settings.png">

11.	On the Security Settings page Click Users.

  <img src="imgs/dyn-settings-security.png">

12.	On the Enabled Users page:
  - `A` Click the check box next to your name
  - `B` Click `Promote to Admin` button
  - `C` Then click `OK` in the alert dialog that comes up

  <img src="imgs/dyn-settings-security-users.png">

13.	Now that we've provisioned our own Dynamics 365 Online tenant with Field Service installed, we need to provision an Azure environment to host the IoT services for our solution.


## Step 2: Provision Azure Trial

## Step 3: Setup MX Chip

## Step 4: Configure Connected Field Service

## Step 5: Write Your First Application

## Step 6: Configure Azure IoT Hub Integration


## My Environment
`{ my dynamics and azure environment details }`

# References
- [Connected Field Service Add-On](https://appsource.microsoft.com/en-us/product/dynamics-365/mscrm.58666c7d-65ee-452d-8708-70b4d471d4c0)
- [Connected Field Service Architecture](https://docs.microsoft.com/en-us/dynamics365/customer-engagement/field-service/developer/connected-field-service-architecture)
- [GitHub icons](https://gist.github.com/rxaviers/7360908)
