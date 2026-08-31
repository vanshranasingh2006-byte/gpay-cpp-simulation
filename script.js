// Update this data to add future skills, projects, certificates, or courses.
const portfolioData = {
  skills: [
    ['Programming languages', ['C#', 'C++', 'Python', 'Java']],
    ['AI / ML', ['NumPy', 'Pandas', 'TensorFlow']],
    ['Game development', ['Godot', 'Unity']],
    ['Tools', ['GitHub', 'Visual Studio Code', 'Visual Studio']],
  ],
  projects: [
    ['01', 'Python · Educational simulation', 'Coffee Machine Simulation', 'A Python coffee-machine simulation with payments, ingredient storage, resource checks, and coffee preparation based on available supplies.', '☕'],
    ['02', 'C++ · Console / OOP simulation', 'C++ GPay Simulation', 'A learning project that models multiple accounts, UPI-ID lookup, PIN validation, balance operations, money transfers, and insufficient-funds checks.', '₹'],
  ],
  achievements: [['20+', 'LeetCode problems solved'], ['5-star', 'HackerRank rating in Java']],
  certifications: ['Java Certification', 'Leadership Certification'],
  courses: [], // Add courses here, for example: 'Introduction to Game Development'
};

const fill = (selector, markup) => document.querySelector(selector).innerHTML = markup;
fill('#skills-grid', portfolioData.skills.map(([name, items]) => `<article class="skill-card reveal"><h3>${name}</h3><div class="tags">${items.map(item => `<span>${item}</span>`).join('')}</div></article>`).join(''));
fill('#project-list', portfolioData.projects.map(([num, type, name, description, symbol]) => `<article class="project-card reveal"><div class="project-num">${num}</div><div><p class="project-type">${type}</p><h3>${name}</h3><p>${description}</p></div><div class="project-symbol">${symbol}</div></article>`).join(''));
fill('#achievement-grid', portfolioData.achievements.map(([number, label]) => `<article class="achievement-card reveal"><strong>${number}</strong><p>${label}</p></article>`).join(''));
fill('#certification-list', portfolioData.certifications.map(item => `<div>${item}</div>`).join(''));
fill('#course-list', portfolioData.courses.length ? portfolioData.courses.map(item => `<div class="course-item">${item}</div>`).join('') : '<div>No courses added yet — update <code>portfolioData.courses</code> in script.js.</div>');
const menuButton = document.querySelector('.menu-toggle');
const nav = document.querySelector('#nav');
menuButton.addEventListener('click', () => { const open = nav.classList.toggle('open'); menuButton.setAttribute('aria-expanded', open); menuButton.textContent = open ? '×' : '☰'; });
nav.querySelectorAll('a').forEach(link => link.addEventListener('click', () => { nav.classList.remove('open'); menuButton.setAttribute('aria-expanded', 'false'); menuButton.textContent = '☰'; }));
const themeButton = document.querySelector('.theme-toggle');
themeButton.addEventListener('click', () => { document.body.classList.toggle('dark'); themeButton.textContent = document.body.classList.contains('dark') ? '☀' : '◐'; });
const profileImage = document.querySelector('#profile-image');
profileImage.addEventListener('load', () => profileImage.parentElement.classList.add('has-image'));
profileImage.src = 'assets/profile-photo.jpg';
const observer = new IntersectionObserver(entries => entries.forEach(entry => { if (entry.isIntersecting) entry.target.classList.add('visible'); }), { threshold: 0.1 });
document.querySelectorAll('.reveal').forEach(element => observer.observe(element));
document.querySelector('#year').textContent = new Date().getFullYear();
