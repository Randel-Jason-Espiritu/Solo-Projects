let menu = document.querySelector('#menu-icon');
let navilist = document.querySelector('.navigation-list');

menu.onclick = () => {
    menu.classList.toggle('bx-x');
    navilist.classList.toggle('open');
}

const sr = ScrollReveal ({
    distance: '65px',
    duration: 2600,
    delay: 450,
    reset: true
});

sr.reveal('.logo-text',{delay:200, origin:'top'});
sr.reveal('.logo-image',{delay:200, origin:'top'});
sr.reveal('.socials',{delay:300, origin:'left'});
sr.reveal('.scroll-down',{delay:300, origin:'right'});
sr.reveal('.logo',{delay:200, origin:'left'});
