# Series-RLC-circuits-voltage-Calculator

This program Calculates the Voltage variation _**`V(t)`**_ with respect to time across Capacitor in _**`Series connected RLC`**_ circuits and print out all found values in _**`.csv`**_ file

# Resistor Calculator

- Hi Guys 🙋‍♂️, This C program use user inputs to calculate :

  _**`V(t)`**_ at any time given with time step _**`d(t)`**_ until the code reach the specefied runtime _**`t`**_ by the user
  <br />
  <br />

- I wrote this code for my university side project and thought it may be useful to someone out there.
- The code print out a list _**`V(t)`**_ values next ot the time of that certian value then stores all values in a _**`.csv`**_ file , the user can use this values to print out a simulation or just simply use the grapg tool in _**`Excel`**_.
  <br />

# The program will do the following

## Ask the User to input

- _**`R`**_ Value of Equavvilent the Resistor
- _**`C`**_ Value of the Capacitor
- _**`L`**_ Value of the Inductor
- _**`V(0)`**_ Voltage at _**`t`**_ < 0
- _**`I(0)`**_ Current at _**`t`**_ < 0
- _**`V(∞)`**_ Voltage at _**`t`**_ > 0
- _**`d(t)`**_ Code run time
- _**`t`**_ Time step

## Calculates

- _**`Alfa`**_
- _**`W0`**_
- Value of _**`dv/dt`**_ using Current on capacitor law
  <img align="right" width="200" height="100" src="https://www.electronics-tutorial.net/wp-content/uploads/2015/09/Cap24.png">

<br /> <br /> <br /> <br />

> **Then dpending on the respond of the circuit the code will excute one of the folllowing cases :** > <br /> <br />

<br />

<span style="color:purple"> **Case 1** </span> **Overdapmed Law :**
<img align="right" width="450" height="50" src="https://user-images.githubusercontent.com/112458142/211697726-30b48d3b-b8e5-49e5-9649-d1af83231f76.png">

<br />

- _**`S1`**_, _**`S2`**_
- _**`A1`**_, _**`A2`**_ --> roots of the Equation
- _**`V(t)`**_
  <br /> <br />

<span style="color:purple">**Case 2** </span> **Criticaly Dapmed Law :**
<img align="right" width="440" height="50" src="https://user-images.githubusercontent.com/112458142/211697730-603db502-f6ea-4c9e-9371-914e7a8f1c9b.png">

<br />

- _**`A1`**_, _**`A2`**_ --> roots of the Equation
- _**`V(t)`**_
  <br /> <br />

<span style="color:purple"> **Case 3** </span> **Under Dapmed Law :**
<img align="right" width="450" height="50" src="https://user-images.githubusercontent.com/112458142/211697677-84fbf773-d998-4859-be2d-2e37160f8f04.png">

<br />

- _**`Wd`**_
- _**`A1`**_, _**`A2`**_ --> roots of the Equation
- _**`V(t)`**_

# Refrence Circuit :

<object data="https://s3.us-west-2.amazonaws.com/secure.notion-static.com/1f7dd5c4-47c5-46f6-82d1-ec3f44e9838c/Refrence_Crcut.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230111%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230111T014021Z&X-Amz-Expires=86400&X-Amz-Signature=eb0b7fd1cfac2f3302d6fc7d340f516093cc32c437a51144b18c6c6aacc85bdd&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Refrence%2520C%25C4%25B1rcu%25C4%25B1t.pdf%22&x-id=GetObject" type="application/pdf" width="200px" height="100px">
    <embed src="https://s3.us-west-2.amazonaws.com/secure.notion-static.com/1f7dd5c4-47c5-46f6-82d1-ec3f44e9838c/Refrence_Crcut.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230111%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230111T014021Z&X-Amz-Expires=86400&X-Amz-Signature=eb0b7fd1cfac2f3302d6fc7d340f516093cc32c437a51144b18c6c6aacc85bdd&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Refrence%2520C%25C4%25B1rcu%25C4%25B1t.pdf%22&x-id=GetObject">
        <p>This browser does not support PDFs. You can download the PDF to view it: <a href="https://s3.us-west-2.amazonaws.com/secure.notion-static.com/1f7dd5c4-47c5-46f6-82d1-ec3f44e9838c/Refrence_Crcut.pdf?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20230111%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20230111T014021Z&X-Amz-Expires=86400&X-Amz-Signature=eb0b7fd1cfac2f3302d6fc7d340f516093cc32c437a51144b18c6c6aacc85bdd&X-Amz-SignedHeaders=host&response-content-disposition=filename%3D%22Refrence%2520C%25C4%25B1rcu%25C4%25B1t.pdf%22&x-id=GetObject">Download PDF</a>.</p>
    </embed>
</object>

# Flowchart

![Akış Şeması 2 drawio](https://user-images.githubusercontent.com/112458142/211697847-23652435-704b-49f2-bda9-0a04bbf82823.png)

# Simulation obtained from the code excution

<img align="right" width="1000" height="450" src="https://user-images.githubusercontent.com/112458142/211703061-73d28bb3-77b0-4f6c-bd06-094a22b173f5.png">
<br /> <br /> <br /> <br /> <br /> <br /><br /> <br /><br /> <br /><br /> <br /><br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br />

<img align="right" width="1000" height="450" src="https://user-images.githubusercontent.com/112458142/211703069-1482f14d-61e6-4ad3-af75-106a79e7cef3.png">
<br /> <br /> <br /> <br /> <br /> <br /><br /> <br /><br /> <br /><br /> <br /><br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br /> <br />

<img align="right" width="1000" height="450" src="https://user-images.githubusercontent.com/112458142/211702981-fefaac78-fa4a-4126-ab8a-efa631939ce9.png">
