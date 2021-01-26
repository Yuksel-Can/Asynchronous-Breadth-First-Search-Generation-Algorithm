# Asynchronous-Breadth-First-Search-Generation-Algorithm
 BFS priority search algorithm is used in this network application developed with Omnet ++.
 <br/>
 ``` OMNeT++ ile geliştirilen bu ağ uygulamasında BFS öncelikli arama algoritması kullanılmıştır. ```
## Function
 ``` Herhangi bir G çizgesinden BFS ağacını oluşturan algoritma, Update_BFS adı verilen Bellman-Ford algoritmasının dağıtık başka bir çeşididir. Tek bir başlatıcı düğüm (node) var, bunun da komşu düğümlerle mesafe bilgisini içeren layer(l) mesajı vardır. Bir layer(l) mesajını alan herhangi bir düğüm, mesajdaki l katman değerini bilinen uzaklığı ile kök (root) düğüm ile karşılaştırır ve eğer yeni değer daha küçükse, katman mesajının göndereni yeni ebeveyn olarak etiketlenir ve mesafe l olarak güncellenir. Kök düğüme olan yeni mesafe tüm komşuları ve diğer düğümleri etkileyeceğinden, yeni mesafeyi içeren layer(l + 1) mesajı Projemizde ve alt kısımda ekran görüntülerinde gösterildiği gibi yeni ebeveyn dışındaki tüm komşulara gönderilmektedir. Bu işlemin sonunda kök düğümden başlayan bir BFS ağacının oluşturulduğu görülebilmektedir. Algoritmanın sonlandırma koşulu, G çizgesinin çapı (diameter) olacak herhangi iki düğüm arasındaki en uzun yolun geçişi olacaktır. ```
## Prerequisites
Android Studio must be installed to run, review and use the project.
<br/>
The project was developed in the Linux-based operating system Ubuntu.
<br/>
```Proje, Linux tabanlı işletim sistemi Ubuntu üzerinde geliştirilmiştir.```
<br/>
```Projeyi çalıştırmak, incelemek ve kullanmak için omnet++ geliştirme ortamı yüklü olmalıdır.```
## How to run
Download the repository
<br/>
Run the files with `OMNeT++`
## Screenshots
![git1](https://github.com/Yuksel-Can/Asynchronous-Breadth-First-Search-Generation-Algorithm/blob/main/Screenshots/github_ss1.jpg)
![git2](https://github.com/Yuksel-Can/Asynchronous-Breadth-First-Search-Generation-Algorithm/blob/main/Screenshots/github_ss2.jpg)
![git3](https://github.com/Yuksel-Can/Asynchronous-Breadth-First-Search-Generation-Algorithm/blob/main/Screenshots/github_ss3.jpg)
![git4](https://github.com/Yuksel-Can/Asynchronous-Breadth-First-Search-Generation-Algorithm/blob/main/Screenshots/github_ss4.jpg)
## Issues
*There are more than one problem and bug in the project. I am waiting for all your help and support for application problems
<br/>
```Projemde birdan fazla sorun-bug bulunmaktadır.Her türlü yardım ve destekleriniz için Issues kımına bekliyorum```

